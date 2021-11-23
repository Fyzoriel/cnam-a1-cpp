//
// Created by Fyzoriel on 23/11/2021.
//

#ifndef TP5_GAMEREVERSI_H
#define TP5_GAMEREVERSI_H

#include "Grids/Reversi/ReversiGrid.h"
#include "Game.h"

class GameReversi : public Game
{
public:
    GameReversi();
    void start() override;

private:
    ReversiGrid m_grid;
};


#endif //TP5_GAMEREVERSI_H
