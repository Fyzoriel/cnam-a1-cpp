//
// Created by Fyzoriel on 13/10/2021.
//

#include "TicTacToeGrid.h"
#include "Cell/Cell.h"
#include "utils/AskUser.h"

TicTacToeGrid::TicTacToeGrid() : GridLine(3, 3, 3)
{

}

void TicTacToeGrid::addToken(const Player &player)
{
    int x, y;
    do
    {
        x = AskUser::askNumber(m_columns);

        y = AskUser::askNumber(m_lines);
    } while (!isEmptyCell(x, y));

    m_grid[y][x].addToken(player);
}
