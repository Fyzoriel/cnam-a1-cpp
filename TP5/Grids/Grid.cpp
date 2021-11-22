//
// Created by Fyzoriel on 26/10/2021.
//

#include "Grid.h"
#include <vector>
#include <iostream>

Grid::Grid(int lines, int columns) : m_lines(lines), m_columns(columns)
{

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
    for (int y = 0; y < m_lines; y++)
    {
        for (int x = 0; x < m_columns; x++)
        {
            if (m_grid[y][x].isEmpty())
            {
                return false;
            }
        }
    }
    return true;
}

void Grid::initArray() {
    m_grid = std::vector<std::vector<Cell>>(m_lines, std::vector<Cell>(m_columns, Cell()));
}