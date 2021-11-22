//
// Created by Fyzoriel on 26/10/2021.
//

#include "Connect4Grid.h"
#include "Utils/AskUser.h"

/* Public methods */
Connect4Grid::Connect4Grid() : GridLine(4,7,4){}

void Connect4Grid::addToken(const Player &player)
{
    bool isCorrectPos = false;
    do
    {
        int x = AskUser::askNumber(m_columns);

        for (int y = m_lines-1; y >= 0; y--)
        {
            if (isEmptyCell(x, y))
            {
                m_grid[y][x].addToken(player);
                isCorrectPos = true;
            }
        }
    } while (!isCorrectPos);
}

/* Private methods */