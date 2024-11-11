cmake_minimum_required(VERSION 3.28)
project(ucsd)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include/)

add_executable(ucsd main.cpp
        main.cpp
        a/a.cpp
        l/l.cpp
        l/l.cpp
        b/b.cpp
        f/f.cpp)
