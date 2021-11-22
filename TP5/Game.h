//
// Created by Fyzoriel on 13/10/2021.
//

#ifndef TP3_GAME_H
#define TP3_GAME_H

#include <Grids/Grid.h>

class Game
{
public:

    explicit Game(Grid& grid);

    void start();

private:
    Player m_players[2] = {};
    Grid& m_grid;
    int m_playerTurn = 0;

    void restart();
    void changePlayer();

    Player playingPlayer();

    void addToken(const Player &player);
};


#endif //TP3_GAME_H
