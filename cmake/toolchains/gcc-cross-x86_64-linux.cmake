# Cross-compile toolchain for x86_64-linux with GCC

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)
set(GCC_TRIPLE x86_64-linux-gnu)
include(${CMAKE_CURRENT_LIST_DIR}/base/gcc-cross.cmake)
