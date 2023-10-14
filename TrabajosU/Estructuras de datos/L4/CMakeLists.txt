cmake_minimum_required(VERSION 3.25)
project(L4)

set(CMAKE_CXX_STANDARD 20)

add_executable(L4 main.cpp List.h List.cpp Stack.h Stack.cpp Punto.cpp Punto.h Laberinto.cpp Laberinto.h)
