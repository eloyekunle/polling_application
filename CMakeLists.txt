cmake_minimum_required(VERSION 3.5)
project(Polling)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    Polling.cpp
    Polling.h)

add_executable(Polling ${SOURCE_FILES})