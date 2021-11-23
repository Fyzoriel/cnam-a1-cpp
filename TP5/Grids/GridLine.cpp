//
// Created by Fyzoriel on 10/11/2021.
//

#include "GridLine.h"

GridLine::GridLine(int x, int y, int tokenInLine) : Grid(x, y), m_tokenInLine(tokenInLine){}

/**
 * Check if a line has been complete by a player according to the number of cells in row needed
 * @param line The number of the line to check
 * @param player The player we want to check if he has complete the line
 * @return true if line is completed
 */
bool GridLine::isLineComplete(int line, const Player &player)
{
    int lineCounter = 0;
    for (int x = 0; x < m_columns; x++)
    {
        if (m_grid[line][x].getColor() == player.getColor())
        {
            lineCounter++;
        }
        else
        {
            lineCounter = 0;
        }

        if (lineCounter == m_tokenInLine)
        {
            return true;
        }
    }
    return false;
}

/**
 * Check if a column has been complete by a player according to the number of cells in row needed
 * @param column The number of the column to check
 * @param player The player we want to check if he has complete the column
 * @return true if column is completed
 */
bool GridLine::isColumnComplete(int column, const Player &player)
{

    int lineCounter = 0;
    for (int y = m_lines-1; y >= 0; y--)
    {
        if (m_grid[y][column].getColor() == player.getColor())
        {
            lineCounter++;
        }
        else
        {
            lineCounter = 0;
        }

        if (lineCounter == m_tokenInLine)
        {
            return true;
        }
    }

    return false;
}

/**
 * Check if at least one diagonal has been complete by a player according to the number of cells in row needed
 * @param player The player we want to check if he has complete the column
 * @return true if at least one diagonal is completed
 */
bool GridLine::isDiagonalComplete(const Player &player)
{
    const char color = player.getColor();

    //   3
    //  2
    // 1
    // for each column, line, check diagonal (from bottom left to top right), Start at bottom left

    // y = max l size - 1
    // y limit = max l size - 1 - (max l size - line size + 1)
    // x = 0
    // x limit = max c size - line size + 1
    for (int y = m_lines-1; y > m_lines-2; y--)
    {
        for (int x = 0; x <= m_columns-m_tokenInLine; x++)
        {
            int lineCounter = 0;
            for (int i = 0; i < m_tokenInLine; i++)
            {
                if (m_grid[y - i][x + i].getColor() == color)
                {
                    lineCounter++;
                }
                if (lineCounter == m_tokenInLine)
                {
                    return true;
                }
            }
        }
    }

    // 3
    //  2
    //   1
    // for each column, line, check diagonal (from bottom right to top left), Start at bottom right

    // y = max l size - 1
    // y limit = line size - 2
    // x = max c size - 1
    // x limit = max c size - line size
    for (int y = m_lines-1; y > m_lines-2; y--)
    {
        for (int x = m_columns-1; x >= m_columns-m_tokenInLine; x--)
        {
            int cellNumber = 0;
            for (int i = 0; i < m_tokenInLine; i++)
            {
                if (m_grid[y - i][x - i].getColor() == color)
                {
                    cellNumber++;
                }
                if (cellNumber == m_tokenInLine)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

/**
 * Check if a player is the winner
 * @param player The player we want to check the win
 * @return true if player is the winner
 */
bool GridLine::isWinner(const Player &player)
{
    for (int i = 0; i < m_columns; i++)
    {
        if (isColumnComplete(i, player))
        {
            return true;
        }
    }

    for (int i = 0; i < m_lines; i++)
    {
        if (isLineComplete(i, player))
        {
            return true;
        }
    }

    return isDiagonalComplete(player);
}

