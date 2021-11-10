//
// Created by Fyzoriel on 13/10/2021.
//

#include <iostream>
#include "Game.h"
#include "Connect4Grid.h"

Game::Game(Grid *grid): m_grid(grid)
{
    m_players[0] = Player('X');
    m_players[1] = Player('O');
    start();
}

void Game::start()
{
    m_grid->initArray();

    bool isFinished = false;
    bool isDraw = false;
    do
    {
        // Get playing player
        Player player = playingPlayer();

        // Display board
        m_grid->displayGrid();

        std::cout << "Player " << m_playerTurn + 1 << std::endl;

        int x = 0, y = 0;


        // Add token
        addToken(player);

        // win or draw
        if (m_grid->isWinner(player) || m_grid->isFull())
        {
            isFinished = true;
            isDraw = m_grid->isFull();
        }
        else
        {
            changePlayer();
        }
    } while(!isFinished);

    // Display board
    m_grid->displayGrid();

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
        start();
    }
}

int Game::askNumber()
{
    int ask;
    bool retry;
    do
    {
        std::cin >> ask;

        retry = std::cin.fail() || ask < 0 || ask > 9;
        if (retry)
        {
            std::cout << std::endl << "You have to enter a valid number: " << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    } while (retry);

    return ask;
}

Player Game::playingPlayer()
{
    return m_players[m_playerTurn];
}

void Game::changePlayer()
{
    m_playerTurn = (m_playerTurn + 1) % 2;
}

void Game::addToken(const Player &player)
{
    int x = 0, y = 0;

    if (dynamic_cast<TicTacToeGrid*>(m_grid) != nullptr)
    {
        do
        {
            std::cout << "Enter line: ";
            y = askNumber();

            std::cout << "Enter column: ";
            x = askNumber();
        } while(! m_grid->addToken(player, x, y) || y >= m_grid->m_lines || x >= m_grid->m_columns );

    }
    else if (dynamic_cast<Connect4Grid*>(m_grid) != nullptr)
    {
        do
        {
            std::cout << "Enter column: ";
            x = askNumber();
        } while(! m_grid->addToken(player, x ,y) || x >= m_grid->m_columns);
    }
}

