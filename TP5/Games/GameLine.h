//
// Created by Fyzoriel on 23/11/2021.
//

#ifndef TP5_GAMELINE_H
#define TP5_GAMELINE_H

#include "Grids/GridLine.h"
#include "Game.h"

class GameLine : public Game
{
public:
    explicit GameLine(GridLine& m_grid);
    void start() override;

private:
    GridLine& m_grid;
};


#endif //TP5_GAMELINE_H
