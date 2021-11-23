//
// Created by Fyzoriel on 26/10/2021.
//

#include "Connect4Grid.h"
#include "Utils/AskUser.h"

Connect4Grid::Connect4Grid() : GridLine(4,7,4){}

/**
 * Add token to the connect 4 grid
 * @param player The player who add the token
 */
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
                m_grid[y][x].setColor(player.getColor());
                isCorrectPos = true;
                break;
            }
        }
    } while (!isCorrectPos);
}