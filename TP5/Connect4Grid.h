//
// Created by Fyzoriel on 26/10/2021.
//

#include "Player.h"
#include "Cell.h"
#include "Grid.h"

#ifndef TP3_CONNECT4GRID_H
#define TP3_CONNECT4GRID_H

#endif //TP3_CONNECT4GRID_H

class Connect4Grid : public Grid
{

public:
    Connect4Grid();

    bool addToken(const Player &player, int x, int y) override;
};