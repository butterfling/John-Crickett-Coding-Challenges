cmake_minimum_required(VERSION 3.27)
project(commandLineTool)

set(CMAKE_CXX_STANDARD 17)

add_executable(commandLineTool src/main.cpp
        include/count.h
        include/dependencies.h
        src/count.cpp
        include/error.h
        include/stats.h
        src/stats.cpp)
