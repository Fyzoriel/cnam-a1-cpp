//
// Created by Fyzoriel on 13/10/2021.
//

#ifndef TP3_GAME_H
#define TP3_GAME_H

#include <Grids/Grid.h>

class Game
{
public:

    Game();
    virtual void start() = 0;

protected:
    Player m_players[2] = {};
    int m_playerTurn;

    void restart();
    void changePlayer();

    Player playingPlayer();
};


#endif //TP3_GAME_H
