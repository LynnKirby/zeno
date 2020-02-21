#!/usr/bin/env python3
# SPDX-License-Identifier: CC0-1.0

"""Run wasmtime with sandbox settings for tests.

usage: wasmtime-runner.py WASMTIME MODULE
"""

import asyncio
import os
import sys
from asyncio.subprocess import PIPE


async def print_stream(stream, out):
    while True:
        line = await stream.readline()
        if not line:
            break
        out(line)


async def run_command_and_print(program, args):
    process = await asyncio.create_subprocess_exec(
        program, *args, stdout=PIPE, stderr=PIPE)
    try:
        await asyncio.gather(
            print_stream(process.stdout, sys.stdout.buffer.write),
            print_stream(process.stderr, sys.stderr.buffer.write))
    except Exception:
        process.kill()
        raise
    finally:
        exit_status = await process.wait()
    return exit_status


if len(sys.argv) < 3:
    print("error: missing arguments")
    print(__doc__.strip().splitlines()[-1])
    sys.exit(1)

#
# Setup arguments.
#

wasmtime = sys.argv[1]
module = sys.argv[2]

args = [
    "run"
]

# Give access to all environment variables starting with "TEST_".
for env in os.environ:
    if env.startswith("TEST_"):
        args.append("--env")
        args.append(f"{env}={os.environ[env]}")

args.append(module)

#
# Setup asyncio and run the program.
#

if os.name == 'nt':
    loop = asyncio.ProactorEventLoop()
    asyncio.set_event_loop(loop)
else:
    loop = asyncio.get_event_loop()

exit_status = loop.run_until_complete(run_command_and_print(wasmtime, args))
loop.close()
sys.exit(exit_status)
