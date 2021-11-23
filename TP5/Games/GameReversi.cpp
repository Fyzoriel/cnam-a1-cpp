//
// Created by Fyzoriel on 23/11/2021.
//

#include <iostream>
#include "GameReversi.h"

GameReversi::GameReversi() : m_grid(ReversiGrid()){}

/**
 * Start reversi game
 */
void GameReversi::start()
{
    m_grid.setColors(m_players[0].getColor(), m_players[1].getColor());
    m_grid.initArray();
    bool isFinished = false;
    bool hasAlreadySkip = false;

    do
    {
        // Get playing player
        Player player = playingPlayer();

        if (!m_grid.canPlay(player))
        {
            if (hasAlreadySkip)
            {
                break;
            }
            hasAlreadySkip = true;
            changePlayer();
            continue;
        }

        // Display board
        m_grid.displayGrid();

        std::cout << "Player " << m_playerTurn + 1 << std::endl;

        // Add token
        m_grid.addToken(player);

        // win or draw
        if (m_grid.isFull())
        {
            isFinished = true;
        }
        else
        {
            changePlayer();
        }
    } while(!isFinished);

    // Display board
    m_grid.displayGrid();

    int scorePlayer1, scorePlayer2, scoreNeutral;

    m_grid.getScores(scorePlayer1, scorePlayer2, scoreNeutral);

    // Display draw or player who won
    if (scorePlayer1 > scorePlayer2)
    {
        std::cout << "Player 1" << " has won with " << (scorePlayer1 + scoreNeutral) << " tokens - " << scorePlayer2 << std::endl;
    }
    else if (scorePlayer1 < scorePlayer2)
    {
        std::cout << "Player 2" << " has won with " << (scorePlayer2 + scoreNeutral) << " tokens - " << scorePlayer1 << std::endl;

    }
    else
    {
        std::cout << "Draw " << scorePlayer1 << " - " << scorePlayer2 << " | " << scoreNeutral << std::endl;
    }
    restart();
}