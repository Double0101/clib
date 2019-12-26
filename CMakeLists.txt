cmake_minimum_required( VERSION 2.8 )
project( clib )

set ( CMAKE_C_COMPILER /usr/local/Cellar/gcc/8.2.0/bin/gcc-8 )
set ( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

include_directories ( ${PROJECT_SOURCE_DIR}/include )

add_subdirectory( util )
add_subdirectory( example )