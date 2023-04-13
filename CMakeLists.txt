cmake_minimum_required(VERSION 3.25)
project(white_belt_CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_executable(white_belt_CPP
        headers/solutions.h
        src/factorial.cpp
        src/funcs.cpp
        src/is_palindrome.cpp
        main.cpp src/SortedStrings.cpp src/Person.cpp)
