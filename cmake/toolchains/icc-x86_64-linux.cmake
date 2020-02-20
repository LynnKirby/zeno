# Multilib toolchain for x86_64-linux using the Intel C/C++ Compiler

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

string(APPEND CMAKE_C_FLAGS " -m64")
string(APPEND CMAKE_CXX_FLAGS " -m64")
string(APPEND CMAKE_ASM_FLAGS " -m64")

include(${CMAKE_CURRENT_LIST_DIR}/base/icc.cmake)
