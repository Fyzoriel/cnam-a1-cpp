//
// Created by Fyzoriel on 26/10/2021.
//

#ifndef TP3_GRID_H
#define TP3_GRID_H

#include <vector>
#include "Player.h"
#include "Cell/Cell.h"

class Grid
{
public:
    Grid(int lines, int columns);

    virtual ~Grid() = default;

    virtual void addToken(const Player &player) = 0;

    virtual bool isWinner(const Player &player) = 0;

    void displayGrid();

    bool isEmptyCell(int x, int y);
    bool isFull();

    virtual void initArray();

protected:
    std::vector<std::vector<Cell>> m_grid;
    const int m_lines;
    const int m_columns;
};


#endif //TP3_GRID_H
