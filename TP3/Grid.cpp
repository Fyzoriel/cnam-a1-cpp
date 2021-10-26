//
// Created by Fyzoriel on 26/10/2021.
//

#include "Grid.h"
#include <vector>
#include <iostream>

Grid::Grid(int lines, int columns, int tokenInLine) : m_lines(lines), m_columns(columns), m_tokenInLine(tokenInLine)
{

}

bool Grid::isWinner(const Player &player)
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

void Grid::displayGrid()
{
    for (int y = 0; y < m_lines; y++)
    {
        for (int x = 0; x < m_columns; x++)
        {
            std::cout << "| " << m_grid[y][x].getValue() << " ";
        }
        std::cout << "|" << std::endl;
    }
}

bool Grid::isEmptyCell(int x, int y)
{
    return m_grid[y][x].getValue() == ' ';
}

bool Grid::isFull()
{
    for (int y = 0; y < m_columns-1; y++)
    {
        for (int x = 0; x < m_lines-1; x++)
        {
            if (m_grid[y][x].isEmpty())
            {
                return false;
            }
        }
    }
    return true;
}

/*
 *
 */
bool Grid::isLineComplete(int line, const Player &player)
{
    int lineCounter = 0;
    for (int x = 0; x < m_columns; x++)
    {
        if (m_grid[line][x].getValue() == player.getColor())
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

bool Grid::isColumnComplete(int column, const Player &player)
{

    int lineCounter = 0;
    for (int y = m_lines-1; y > 0; y--)
    {
        if (m_grid[y][column].getValue() == player.getColor())
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

bool Grid::isDiagonalComplete(const Player &player)
{
    const char color = player.getColor();

    //   3
    //  2
    // 1
    // for each column, line, check diagonal (from bottom left to top right), Start at bottom left

    // y = max l size - 1 --> 4-1 = 3
    // y limit = max l size - 1 - (max l size - line size + 1) --> line size - 2 --> 4 - 2 = 2
    // x = 0
    // x limit = max c size - line size + 1 --> 7 - 4 = 3
    for (int y = m_lines-1; y > m_lines-2; y--)
    {
        for (int x = 0; x <= m_columns-m_tokenInLine; x++)
        {
            int lineCounter = 0;
            for (int i = 0; i < m_tokenInLine-1; i++)
            {
                if (m_grid[y - i][x + i].getValue() == color)
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

    // y = max l size - 1 --> 4-1 = 3
    // y limit = line size - 2 --> 4 - 2 = 2
    // x = max c size - 1 --> 7 - 1
    // x limit = max c size - line size --> 7 - 4 = 3

    for (int y = m_lines-1; y > m_lines-2; y--)
    {
        for (int x = m_columns-1; x >= m_columns-m_tokenInLine; x--)
        {
            int cellNumber = 0;
            for (int i = 0; i < m_tokenInLine-1; i++)
            {
                if (m_grid[y - i][x - i].getValue() == color)
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

void Grid::initArray() {
    m_grid = std::vector<std::vector<Cell>>(m_lines, std::vector<Cell>(m_columns, Cell()));
}
