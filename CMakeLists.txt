cmake_minimum_required(VERSION 3.15)
project(five_chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(five_chess main.cpp board.cpp board.h Loops.cpp Loops.h LastOrder.cpp LastOrder.h Simulation.cpp Simulation.h)