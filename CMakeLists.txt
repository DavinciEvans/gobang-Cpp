cmake_minimum_required(VERSION 3.15)
project(goBang-win)

set(CMAKE_CXX_STANDARD 14)

add_executable(goBang-win main.cpp board.cpp board.h Loops.cpp Loops.h LastOrder.cpp LastOrder.h Simulation.cpp Simulation.h Debug.cpp Debug.h)