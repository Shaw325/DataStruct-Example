cmake_minimum_required(VERSION 2.8)
project(DataStructure)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++11")
file (GLOB files *.cpp */*cpp)
foreach(file ${files})
#    message(\ \ \ \ --\ ${file})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    string(REGEX REPLACE ".+/(.+)/(.+)\\..*" "\\1-\\2" exe ${file})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
    endforeach()
#
#add_executable(DataStructure.cpp)