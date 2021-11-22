//
// Created by Fyzoriel on 26/10/2021.
//

#include "Player.h"
#include "Cell/Cell.h"
#include "Grids/Grid.h"
#include "Grids/GridLine.h"

#ifndef TP3_CONNECT4GRID_H
#define TP3_CONNECT4GRID_H

#endif //TP3_CONNECT4GRID_H

class Connect4Grid : public GridLine
{

public:
    Connect4Grid();

    void addToken(const Player &player) override;
};