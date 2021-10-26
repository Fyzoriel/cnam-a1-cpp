cmake_minimum_required(VERSION 3.20)
project(TP3)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP3 main.cpp TicTacToeGrid.cpp TicTacToeGrid.h Game.cpp Game.h Cell.cpp Cell.h Player.cpp Player.h Connect4Grid.cpp Connect4Grid.h Grid.cpp Grid.h)
