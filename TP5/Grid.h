//
// Created by Fyzoriel on 26/10/2021.
//

#ifndef TP3_GRID_H
#define TP3_GRID_H

#include <vector>
#include "Player.h"
#include "Cell.h"

class Grid
{
public:
    Grid(int lines, int columns, int tokenInLine);

    virtual ~Grid() = default;

    virtual bool addToken(const Player &player, int x, int y) = 0;

    bool isWinner(const Player &player);

    void displayGrid();

    bool isEmptyCell(int x, int y);
    bool isFull();
    void initArray();

    const int m_lines;
    const int m_columns;
protected:
    std::vector<std::vector<Cell>> m_grid;

private:

    const int m_tokenInLine;
    bool isLineComplete(int line, const Player &player);
    bool isColumnComplete(int column, const Player &player);
    bool isDiagonalComplete(const Player &player);
};


#endif //TP3_GRID_H
