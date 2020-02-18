#!/usr/bin/env python3
# SPDX-License-Identifier: CC0-1.0

"""Copies FILEs into OUTDIR and removes all extensions except the last one.

usage: copy-objlib.py FILE [FILE...] OUTDIR
"""

import os
import sys
from distutils import file_util


def try_relpath(path):
    """Safer version of os.path.relpath."""
    # FIXME: This will fail on Windows if path and CWD are on different drives.
    # Need to run on Windows and see which error it is.
    return os.path.relpath(path, os.getcwd())


if len(sys.argv) < 3:
    print("error: missing arguments")
    print(__doc__.strip().splitlines()[-1])
    sys.exit(1)

outdir = try_relpath(sys.argv[-1])
files = sys.argv[1:-1]

os.makedirs(outdir, exist_ok=True)

for path in files:
    infile = try_relpath(path)

    base = os.path.basename(path)
    root, ext = os.path.splitext(base)
    orig_ext = ext
    while ext != "":
        root, ext = os.path.splitext(root)

    outfile = os.path.join(outdir, root + orig_ext)
    _, copied = file_util.copy_file(infile, outfile, update=True)
    if copied:
        print(f"-- Copied object library file: {outfile}")
