//
// Created by boybe on 21/11/2021.
//

#include <iostream>

#include "Utils/AskUser.h"
#include "ReversiGrid.h"
#include "Player.h"
ReversiGrid::ReversiGrid() : Grid(8,8){}


bool ReversiGrid::checkFlipToken(const Player &player, int x, int y, bool flipMode)
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

        if (checkFlipToken(player, x, y, xModifier, yModifier, true, flipMode))
        {
            hasFlip = true;
        }
    }
    if (hasFlip && flipMode)
    {
        m_grid[y][x].setColor(player.getColor());
    }

    return hasFlip;
}

bool ReversiGrid::checkFlipToken(const Player &player, int x, int y, int xModifier, int yModifier, bool first, bool flipMode)
{
    int nextX = x + 1 * xModifier;
    int nextY = y + 1 * yModifier;

    if (nextX < 0 || nextX >= m_columns
        || nextY < 0 || nextY >= m_lines
        || m_grid[nextY][nextX].getColor() == ' ')
    {
        return false;
    }

    if (m_grid[nextY][nextX].getColor() == player.getColor())
    {
        // If first return false (The same color side by side), otherwise return true
        return !first;
    }

    bool canFlip = checkFlipToken(player, nextX, nextY, xModifier, yModifier, false, flipMode);
    if (canFlip && flipMode)
    {
        m_grid[nextY][nextX].setColor(player.getColor());
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

        error = !isEmptyCell(x, y) || !checkFlipToken(player, x, y, true);
        if (error)
        {
            std::cout << "Position invalide" << std::endl;
        }

    } while (error);
}

void ReversiGrid::initArray()
{
    Grid::initArray();

    m_grid[3][3].setColor(m_colorPlayer2);
    m_grid[4][4].setColor(m_colorPlayer2);
    m_grid[3][4].setColor(m_colorPlayer1);
    m_grid[4][3].setColor(m_colorPlayer1);

}

bool ReversiGrid::isWinner(const Player &player)
{
    return false;
}

bool ReversiGrid::canPlay(const Player &player)
{
    for (int x = 0; x < m_columns; x++)
    {
        for (int y = 0; y < m_lines; y++)
        {
            if (checkFlipToken(player, x, y, false))
            {
                return true;
            }
        }
    }
    return false;
}

void ReversiGrid::getScores(int &scorePlayer1, int &scorePlayer2, int &scoreNeutral)
{
    int p1= 0, p2 = 0, ne = 0;
    for (int x = 0; x < m_columns; x++)
    {
        for (int y = 0; y < m_lines; y++)
        {
            if (m_grid[y][x].getColor() == m_colorPlayer1)
            {
                p1++;
            }
            else if (m_grid[y][x].getColor() == m_colorPlayer2)
            {
                p2++;
            }
            else
            {
                ne++;
            }
        }
    }
    scorePlayer1 = p1;
    scorePlayer2 = p2;
    scoreNeutral = ne;
}

void ReversiGrid::setColors(char color1, char color2)
{
    m_colorPlayer1 = color1;
    m_colorPlayer2 = color2;
}
