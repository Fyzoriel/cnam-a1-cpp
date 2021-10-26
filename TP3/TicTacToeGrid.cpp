//
// Created by Fyzoriel on 13/10/2021.
//

#include "TicTacToeGrid.h"
#include "Cell.h"

TicTacToeGrid::TicTacToeGrid() : Grid(3, 3, 3) {}

bool TicTacToeGrid::addToken(const Player &player, int x, int y)
{
    if (isEmptyCell(x, y))
    {
        m_grid[y][x].addToken(player);
        return true;
    }
    return false;
}

