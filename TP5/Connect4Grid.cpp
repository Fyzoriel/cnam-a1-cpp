//
// Created by Fyzoriel on 26/10/2021.
//

#include <iostream>
#include "Connect4Grid.h"

/* Public methods */
Connect4Grid::Connect4Grid() : Grid(4,7,4){}


bool Connect4Grid::addToken(const Player &player, int x, int y)
{
    for (int yy = 3; yy >= 0; yy--)
    {
        if (isEmptyCell(x, yy))
        {
            m_grid[yy][x].addToken(player);
            return true;
        }
    }
    return false;
}

/* Private methods */