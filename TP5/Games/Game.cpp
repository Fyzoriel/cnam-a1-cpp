//
// Created by Fyzoriel on 13/10/2021.
//

#include <iostream>
#include "Game.h"

Game::Game()
{
    m_players[0] = Player('X');
    m_players[1] = Player('O');
    m_playerTurn = 0;
}
/**
 * Ask for restart the game
 */
void Game::restart()
{
    char ask;
    std::cout << "Play again ? (y/n)" << std::endl;
    do
    {
        std::cin >> ask;

    } while (ask != 'y' && ask != 'n');
    if (ask == 'y')
    {
        m_playerTurn = 0;
        start();
    }
}

/**
 * Get the playing player
 * @return the playing player
 */
Player Game::playingPlayer()
{
    return m_players[m_playerTurn];
}

/**
 * Change the playing player
 */
void Game::changePlayer()
{
    m_playerTurn = (m_playerTurn + 1) % 2;
}

