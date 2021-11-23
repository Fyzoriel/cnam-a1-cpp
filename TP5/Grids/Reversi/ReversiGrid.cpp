//
// Created by boybe on 21/11/2021.
//

#include <iostream>

#include "Utils/AskUser.h"
#include "ReversiGrid.h"
#include "Player.h"
ReversiGrid::ReversiGrid() : Grid(8,8)
{}


bool ReversiGrid::flipToken(const Player &player, int x, int y)
{
    bool hasFlip = false;
    for (int i = 0; i < 8; i++)
    {
        int xModifier, yModifier;
        switch (i)
        {
            case 0:
                xModifier = 0;
                yModifier = -1;
                break;
            case 1:
                xModifier = 1;
                yModifier = -1;
                break;
            case 2:
                xModifier = 1;
                yModifier = 0;
                break;
            case 3:
                xModifier = 1;
                yModifier = 1;
                break;
            case 4:
                xModifier = 0;
                yModifier = 1;
                break;
            case 5:
                xModifier = -1;
                yModifier = 1;
                break;
            case 6:
                xModifier = -1;
                yModifier = 0;
                break;
            case 7:
                xModifier = -1;
                yModifier = -1;
                break;
            default:
                xModifier = 0;
                yModifier = 0;
        }

        if (flipToken(player, x, y, xModifier, yModifier, true))
        {
            hasFlip = true;
        }
    }
    if (hasFlip)
    {
        m_grid[y][x].setColor(player.getColor());
    }

    return hasFlip;
}

bool ReversiGrid::flipToken(const Player &player, int x, int y, int xModifier, int yModifier, bool first)
{
    int nextX = x + 1 * xModifier;
    int nextY = y + 1 * yModifier;

    if (nextX < 0 || nextX > m_columns
        || nextY < 0 || nextY > m_lines
        || m_grid[nextY][nextX].getColor() == ' ')
    {
        return false;
    }

    if (m_grid[nextY][nextX].getColor() == player.getColor())
    {
        // If first return false (The same color side by side), otherwise return true
        return !first;
    }

    bool canFlip = flipToken(player, nextX, nextY, xModifier, yModifier, false);
    if (canFlip)
    {
        m_grid[y][x].setColor(player.getColor());
    }
    return canFlip;
}

void ReversiGrid::addToken(const Player &player)
{
    int x, y;
    bool error;
    do
    {
        x = AskUser::askNumber(m_columns);

        y = AskUser::askNumber(m_lines);

        error = !isEmptyCell(x, y) || !flipToken(player, x, y);
        if (error)
        {
            std::cout << "Position invalide" << std::endl;
        }

    } while (error);
}

void ReversiGrid::initArray()
{
    Grid::initArray();

    m_grid[3][3].setColor('X');
    m_grid[4][4].setColor('X');
    m_grid[3][4].setColor('O');
    m_grid[4][3].setColor('O');

}

bool ReversiGrid::isWinner(const Player &player)
{
    return false;
}
