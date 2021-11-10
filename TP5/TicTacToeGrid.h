/**
 * Header file of the m_grid for the tic-tac-toe game
 * @file TicTacToeGrid.h
 * @author Fyzoriel
 * @date 2021/10/13
 */

#ifndef TP3_TICTACTOEGRID_H
#define TP3_TICTACTOEGRID_H

#include <vector>
#include "Player.h"
#include "Cell.h"
#include "Grid.h"

class TicTacToeGrid : public Grid
{

public:
    TicTacToeGrid();

    bool addToken(const Player &player, int x, int y) override;
};


#endif //TP3_TICTACTOEGRID_H
