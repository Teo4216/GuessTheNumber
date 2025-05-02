cmake_minimum_required(VERSION 3.10)
project(Proiect2Poo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proiect2Poo
        main.cpp
        joc.cpp
        regula_feedback.cpp
        utilitare.cpp
)

target_include_directories(Proiect2Poo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})