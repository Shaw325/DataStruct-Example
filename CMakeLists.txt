cmake_minimum_required(VERSION 2.8)
project(DataStructure)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++11")


# file (GLOB_RECURSE files *.cpp)
# foreach (file ${files})
# string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
# add_executable (${exe} ${file})
# message(\ \ \ \ --\ ${exe} \ ${file} \ main)
# # message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
# endforeach ()

# file( GLOB LIB_SOURCES *.cpp )

# file( GLOB LIB_HEADERS *.h )

# add_library( YourLib ${LIB_SOURCES} ${LIB_HEADERS} )


file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
string(REGEX REPLACE ".+/(.+)" "\\1" exe ${file})
# add_executable (${exe} ${file})
message(\ \ \ \ ${exe})
endforeach()