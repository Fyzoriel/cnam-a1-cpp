//
// Created by ben on 21/11/2021.
//

#include "Grids/Grid.h"

#ifndef TP3_REVERSIGRID_H
#define TP3_REVERSIGRID_H

#endif //TP3_REVERSIGRID_H

class ReversiGrid : public Grid
{
public:
    ReversiGrid();

    void initArray() override;

    // bool checkToken(const Player &player, int x, int y);
    void addToken(const Player &player) override;

    bool flipToken(const Player &player, int x, int y, int xModifier, int yModifier, bool first);

    bool flipToken(const Player &player, int x, int y);

    bool isWinner(const Player &player) override;
};