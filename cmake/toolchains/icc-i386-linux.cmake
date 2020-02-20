# Multilib toolchain for i386-linux using the Intel C/C++ Compiler

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR i386)

string(APPEND CMAKE_C_FLAGS " -m32")
string(APPEND CMAKE_CXX_FLAGS " -m32")
string(APPEND CMAKE_ASM_FLAGS " -m32")

include(${CMAKE_CURRENT_LIST_DIR}/base/icc.cmake)
