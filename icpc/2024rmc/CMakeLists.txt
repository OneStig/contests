cmake_minimum_required(VERSION 3.28)
project(2024rmc)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include/)
add_executable(2024rmc main.cpp
        l/l.cpp
        k/k.cpp
        b/b.cpp
        g/g.cpp
        h/h.cpp
        j/j.cpp
        f/f.cpp
        d/d.cpp
        i/i.cpp
        e/e.cpp
        c/c.cpp)
