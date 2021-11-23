/**
 * Header file of the m_grid for the tic-tac-toe game
 * @file TicTacToeGrid.h
 * @author Fyzoriel
 * @date 2021/10/13
 */

#ifndef TP3_TICTACTOEGRID_H
#define TP3_TICTACTOEGRID_H

#include <vector>
#include "Games/Game.h"
#include "Player.h"
#include "Cell/Cell.h"
#include "Grids/Grid.h"
#include "Grids/GridLine.h"

class TicTacToeGrid : public GridLine
{

public:
    TicTacToeGrid();

    void addToken(const Player &player) override;
};


#endif //TP3_TICTACTOEGRID_H
