# Run cmake like this:
#   cmake -D CMAKE_TOOLCHAIN_FILE=../mingw-cross.cmake ..
SET(CMAKE_SYSTEM_NAME Windows)
SET(CMAKE_RC_COMPILER i586-mingw32msvc-windres) # Debian
#SET(CMAKE_RC_COMPILER i686-pc-mingw32-windres) # Cygwin
include(CMakeForceCompiler)
# Prefix detection only works with compiler id "GNU"
# CMake will look for prefixed g++, cpp, ld, etc. automatically
CMAKE_FORCE_C_COMPILER(i586-mingw32msvc-gcc GNU) # Debian
#CMAKE_FORCE_C_COMPILER(i686-pc-mingw32-gcc GNU) # Cygwin
