cmake_minimum_required(VERSION 3.28)
project(2024nena)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include/)
add_executable(2024nena main.cpp
        temp.cpp
        b/b.cpp
        i/i.cpp
        g/g.cpp
        d/d.cpp
        l/l.cpp
        m/m.cpp
        h/h.cpp
        j/j.cpp
        b/b2.cpp
        f/f.cpp)
