//
// Created by Fyzoriel on 10/11/2021.
//

#ifndef TP5_REVERSIGRID_H
#define TP5_REVERSIGRID_H


#include "Grids/Grid.h"

class ReversiGrid : public Grid
{
public:
    ReversiGrid();

    void addToken(const Player &player) override;
    bool isWinner(const Player &player) override;
};


#endif //TP5_REVERSIGRID_H
