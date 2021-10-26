//
// Created by Fyzoriel on 13/10/2021.
//

#ifndef TP3_GAME_H
#define TP3_GAME_H
#include "TicTacToeGrid.h"

class Game
{
public:

    explicit Game(Grid* grid);

    void start();

private:
    Player m_players[2] = {};
    Grid* m_grid;
    int m_playerTurn = 0;

    void restart();
    int askNumber();
    void changePlayer();

    void addToken(const Player &player);

    Player playingPlayer();
};


#endif //TP3_GAME_H
