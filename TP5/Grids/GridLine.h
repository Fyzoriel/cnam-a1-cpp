//
// Created by Fyzoriel on 10/11/2021.
//

#ifndef TP5_GRIDLINE_H
#define TP5_GRIDLINE_H

#include "Player.h"
#include "Grid.h"

class GridLine : public Grid
{
public:
    GridLine(int x, int y, int tokenInLine);

    ~GridLine() override = default;

    void addToken(const Player &player) override = 0;

    bool isWinner(const Player &player) override;

private:
    const int m_tokenInLine;

    bool isLineComplete(int line, const Player &player);
    bool isColumnComplete(int column, const Player &player);
    bool isDiagonalComplete(const Player &player);
};


#endif //TP5_GRIDLINE_H
