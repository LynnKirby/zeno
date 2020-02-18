# Cross-compile toolchain for i386-linux with Clang

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR i386)
set(CLANG_TRIPLE i386-unknown-linux-gnu)
include(${CMAKE_CURRENT_LIST_DIR}/base/clang.cmake)
