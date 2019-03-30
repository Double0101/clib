cmake_minimum_required( VERSION 3.13 )
project( clib )

set ( CMAKE_C_COMPILER /usr/bin/gcc )
set ( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

include_directories ( ${PROJECT_SOURCE_DIR}/include )

add_subdirectory( lib )
add_subdirectory( util )