//
// Created by Fyzoriel on 23/11/2021.
//

#include <iostream>
#include "GameLine.h"

GameLine::GameLine(GridLine& m_grid) : m_grid(m_grid) {}

/**
 * Start game line type
 */
void GameLine::start()
{
    m_grid.initArray();

    bool isFinished = false;
    bool isDraw = false;
    do
    {
        // Get playing player
        Player player = playingPlayer();

        // Display board
        m_grid.displayGrid();

        std::cout << "Player " << m_playerTurn + 1 << std::endl;

        // Add token
        m_grid.addToken(player);

        // win or draw
        if (m_grid.isWinner(player) || m_grid.isFull())
        {
            isFinished = true;
            isDraw = m_grid.isFull();
        }
        else
        {
            changePlayer();
        }
    } while(!isFinished);

    // Display board
    m_grid.displayGrid();

    // Display draw or player who won
    if (isDraw)
    {
        std::cout << "Draw" << std::endl;
    }
    else
    {
        std::cout << "Player " << m_playerTurn + 1 << " has won" << std::endl;
    }
    restart();
}
