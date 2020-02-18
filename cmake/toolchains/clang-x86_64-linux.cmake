# Cross-compile toolchain for x86_64-linux with Clang

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)
set(CLANG_TRIPLE x86_64-unknown-linux-gnu)
include(${CMAKE_CURRENT_LIST_DIR}/base/clang.cmake)
