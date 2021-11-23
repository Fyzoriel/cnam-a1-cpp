cmake_minimum_required(VERSION 3.20)
project(TP5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TP5
        Cell/Cell.cpp
        Cell/Cell.h
        Grids/Connect4/Connect4Grid.cpp
        Grids/Connect4/Connect4Grid.h
        Games/Game.cpp
        Games/Game.h
        Grids/Grid.cpp
        Grids/Grid.h
        main.cpp
        Player.cpp
        Player.h
        Grids/TicTacToe/TicTacToeGrid.cpp
        Grids/TicTacToe/TicTacToeGrid.h Grids/GridLine.cpp Grids/GridLine.h Utils/AskUser.cpp Utils/AskUser.h Grids/Reversi/ReversiGrid.cpp Games/GameLine.cpp Games/GameLine.h Games/GameReversi.cpp Games/GameReversi.h)
