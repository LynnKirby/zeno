#!/usr/bin/env python3
# SPDX-License-Identifier: CC0-1.0

"""Compare program behavior with directives in its source file.

usage: check_program.py SOURCE PROGRAM [PROGRAM ARGS...]
"""

from pathlib import Path
import subprocess
import sys
import re
import logging
from dataclasses import dataclass


@dataclass
class Position:
    line: int
    column: int


def report(exe, msg, pos=None):
    if pos is None:
        print(f"{exe}: {msg}")
    else:
        print(f"{exe}:{pos.line}:{pos.column}: {msg}")


def main() -> int:
    #
    # Handle arguments.
    #

    if len(sys.argv) < 3:
        print("error: missing arguments")
        print(__doc__.strip().splitlines()[-1])
        return 1

    source = sys.argv[1]
    source_text = Path(source).read_text()
    binary = sys.argv[2]

    if len(sys.argv) > 3:
        binary_args = sys.argv[3:]
    else:
        binary_args = []

    #
    # Parse source text for directives.
    #

    # // KEY: value
    check_re = re.compile(r"\s*\/\/\s*(?P<key>\S+):\s*(?P<value>.*)")

    allow_stderr = None
    expected_exit_code = None
    expected_exit_code_position = None
    checks = []
    env = {}

    line_count = 0

    for line in source_text.splitlines():
        line_count += 1
        match = check_re.match(line)

        if not match:
            continue

        key = match["key"]
        value = match["value"]
        pos = Position(line=line_count, column=match.start("key") + 1)

        if key == "CHECK":
            checks.append((pos, value))
        elif key == "RETURN":
            if expected_exit_code is not None:
                report(source, "error: multiple RETURN directives", pos)
                return 1
            expected_exit_code = int(value)
            expected_exit_code_position = pos
        elif key == "ENV":
            env_key, env_value = value.split("=", 1)
            if env_key in env:
                report(source, f"error: multiple ENV directives for '{key}'", pos)
                return 1
            env[env_key] = env_value
        elif key == "ALLOW-STDERR":
            if value == "true":
                allow = True
            elif value == "false":
                allow = False
            else:
                report(source, f"error: invalid boolean value", pos)
                return 1
            if allow_stderr is not None:
                report(source, f"error: multiple ALLOW-STDERR directives", pos)
                return 1
            allow_stderr = allow
        elif key in ("TODO", "FIXME", "XXX"):
            # Ignore developer comments
            pass
        else:
            report(source, f"error: unknown directive {key}", pos)
            return 1

    # Defaults
    if allow_stderr is None:
        allow_stderr = False
    if expected_exit_code is None:
        expected_exit_code = 0

    #
    # Run test binary
    #

    args = [binary]
    args += binary_args

    sp = subprocess.run(
        args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, env=env
    )

    #
    # Check expected output.
    #

    failed = False

    # RETURN directive
    if sp.returncode != expected_exit_code:
        failed = True
        report(source, "Failure", expected_exit_code_position)
        print(f"Exit code: {sp.returncode}")
        print(f" Expected: {expected_exit_code}")
        print()

    # Search for CHECK matches line-by-line. Loop ends if we run out of lines
    # or all the checks are done.
    if len(checks) > 0:
        pos, value = checks[0]

        for line in sp.stdout.splitlines():
            if value in line:
                del checks[0]
                if len(checks) > 0:
                    pos, value = checks[0]
                else:
                    break

    # Only report the earliest failed match.
    if len(checks) > 0:
        failed = True
        pos, value = checks[0]
        report(source, "Failure", pos)
        print(f"Line match failed: {value}")
        print()

    # If stderr should not have been written to. Don't report this if we've
    # already failed. It was probably an assert() doing it, and it'll show up
    # when we print stderr anyways.
    if not failed and not allow_stderr and len(sp.stderr) > 0:
        failed = True
        report(source, "Failure", pos)
        print(f"Program wrote to stderr")
        print()

    if not failed:
        return 0

    if len(sp.stdout) != 0:
        print("stdout:\n")
        print(sp.stdout)

    if len(sp.stderr) != 0:
        print("stderr:\n")
        print(sp.stderr)

    return 1


if __name__ == "__main__":
    sys.exit(main())
