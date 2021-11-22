//
// Created by ben on 21/11/2021.
//

#include <Grids/Grid.h>

#ifndef TP3_REVERSIGRID_H
#define TP3_REVERSIGRID_H

#endif //TP3_REVERSIGRID_H

class ReversiGrid : public Grid
{
public:
    ReversiGrid();

    bool checkToken(const Player &player, int x, int y);
    void addToken(const Player &player) override;

};