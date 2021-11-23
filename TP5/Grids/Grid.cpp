//
// Created by Fyzoriel on 26/10/2021.
//

#include "Grid.h"
#include <vector>
#include <iostream>

Grid::Grid(int lines, int columns) : m_lines(lines), m_columns(columns)
{

}

/**
 * Display the grid with coordinate number and cell values
 */
void Grid::displayGrid()
{
    char separator = '|';
    std::cout << "   " << separator << " ";
    for (int x = 0; x < m_columns; x++)
    {
        std::cout << x+1 << " " << separator << " ";
    }
        std::cout << std::endl;

    for (int y = 0; y < m_lines; y++)
    {
        std::cout << " " << y+1;
        for (int x = 0; x < m_columns; x++)
        {
            std::cout << " " << separator << " " << m_grid[y][x].getColor();
        }
        std::cout << " " << separator << std::endl;
    }
}

/**
 * Check if cell is empty
 * @param x The x coordinate
 * @param y The y coordinate
 * @return true if cell is empty
 */
bool Grid::isEmptyCell(int x, int y)
{
    return m_grid[y][x].getColor() == ' ';
}

/**
 * Check if the grid is full
 * @return true if all cells have values
 */
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

/**
 * Init the grid vector
 */
void Grid::initArray()
{
    m_grid = std::vector<std::vector<Cell>>(m_lines, std::vector<Cell>(m_columns, Cell()));
}