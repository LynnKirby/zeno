#!/usr/bin/env python3
# SPDX-License-Identifier: CC0-1.0
#
# Helper script for the CopyObjectLibrary module.

"""Copies FILEs into OUTDIR and removes all extensions except the last one.

usage: copy_object_library.py FILE [FILE...] OUTDIR
"""

import os
import sys
from distutils import file_util


def try_relpath(path) -> str:
    """Safer version of os.path.relpath."""
    # FIXME: This will fail on Windows if path and CWD are on different drives.
    # Need to run on Windows and see which error it is.
    return os.path.relpath(path, os.getcwd())


def main() -> str:
    if len(sys.argv) < 3:
        print("error: missing arguments")
        print(__doc__.strip().splitlines()[-1])
        return 1

    outdir = sys.argv[-1]
    files = sys.argv[1:-1]

    os.makedirs(outdir, exist_ok=True)

    for infile in files:
        base = os.path.basename(infile)
        root, ext = os.path.splitext(base)
        orig_ext = ext
        while ext != "":
            root, ext = os.path.splitext(root)

        outfile = os.path.join(outdir, root + orig_ext)
        _, copied = file_util.copy_file(infile, outfile, update=True)
        if copied:
            # Use relative path if possible so that the status message will use
            # a compact file name instead of the absolute name that we're given.
            print(f"-- Copied object library file: {try_relpath(infile)}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
