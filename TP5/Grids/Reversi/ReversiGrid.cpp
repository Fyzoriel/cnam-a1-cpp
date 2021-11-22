//
// Created by boybe on 21/11/2021.
//

#include <Utils/AskUser.h>
#include "ReversiGrid.h"
#include "Player.h"
#include "vector"

ReversiGrid::ReversiGrid() : Grid(4,7){}

bool ReversiGrid::checkToken(const Player &player, int x, int y)
{
    int direction = 1;
    char color = player.getColor();
    vector<int> goodDirection;
    while(direction < 9)
    {
        switch (direction)
        {
            case 1: // vers le haut
                int i = 1;
                if (y >= 2)
                {
                    if (color == m_grid[y - i][x].getColor() || m_grid[y - i][x].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (m_grid[y - i][x].getColor() == ' ')
                                direction++;
                            else if (m_grid[y - i][x].getColor() == color)
                                goodDirection.push_back(direction);
                        } while (m_grid[y - i][x].getColor() != color && m_grid[y - i][x].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 2: // diagonale haut droite
                int i = 1;
                if (y >= 2 && x <= 5)
                {
                    if (color == m_grid[y - i][x + i].getColor() || m_grid[y - i][x + i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (m_grid[y - i][x + i].getColor() == ' ')
                                direction++;
                            else if (m_grid[y - i][x + i].getColor() == color)
                                goodDirection.push_back(direction);
                        } while (m_grid[y - i][x + i].getColor() != color && m_grid[y - i][x + i].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 3: // vers la droite
                int i = 1;
                if (x <= 5)
                {
                    if (color == m_grid[y][x + i].getColor() || m_grid[y][x + i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (m_grid[y][x + i].getColor() == ' ')
                                direction++;
                            else if (m_grid[y][x + i].getColor() == color)
                                goodDirection.push_back(direction);
                        } while (m_grid[y][x + i].getColor() != color && m_grid[y][x + i].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 4: // diagonale bas droite
                int i = 1;
                if (y <= 5 && x <= 5)
                {
                    if (color == m_grid[y + i][x + i].getColor() || m_grid[y + i][x + i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (m_grid[y + i][x + i].getColor() == ' ')
                                direction++;
                            else if (m_grid[y + i][x + i].getColor() == color)
                                goodDirection.push_back(direction);
                        } while (m_grid[y + i][x + i].getColor() != color && m_grid[y + i][x + i].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 5: // vers le bas
                int i = 1;
                if (y <= 5)
                {
                    if (color == m_grid[y + i][x].getColor() || m_grid[y + i][x].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (m_grid[y + i][x].getColor() == ' ')
                                direction++;
                            else if (m_grid[y + i][x].getColor() == color)
                                goodDirection.push_back(direction);
                        } while (m_grid[y + i][x].getColor() != color && m_grid[y + i][x].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 6: // diagonale bas gauche
                int i = 1;
                if (y <= 5 && x >= 2)
                {
                    if (color == m_grid[y + i][x - i].getColor() || m_grid[y + i][x - i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (m_grid[y + i][x - i].getColor() == ' ')
                                direction++;
                            else if (m_grid[y + i][x - i].getColor() == color)
                                goodDirection.push_back(direction);
                        } while (m_grid[y + i][x - i].getColor() != color && m_grid[y + i][x - i].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 7: // vers la gauche
                int i = 1;
                if (x >= 2)
                {
                    if (color == m_grid[y][x - i].getColor() || m_grid[y][x - i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (m_grid[y][x - i].getColor() == ' ')
                                direction++;
                            else if (m_grid[y][x - i].getColor() == color)
                                goodDirection.push_back(direction);
                        } while (m_grid[y][x - i].getColor() != color && m_grid[y][x - i].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 8: // diagonale haut gauche
                int i = 1;
                if (y >= 2 && x >= 2)
                {
                    if (color == m_grid[y - i][x - i].getColor() || m_grid[y - i][x - i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (m_grid[y - i][x - i].getColor() == ' ')
                                direction++;
                            else if (m_grid[y - i][x - i].getColor() == color)
                                goodDirection.push_back(direction);
                        } while (m_grid[y - i][x - i].getColor() != color && m_grid[y - i][x - i].getColor() != ' ');
                    }
                }
                else
                    direction++;

        }
    }
    if(goodDirection.empty())
        return false;
    else
    {
        int direc = 0;
        for (int z = 0; z < goodDirection.size(); z++) { // pour retourner les jetons
            direc = goodDirection[z];
            switch (direc) {
                case 1: // vers le haut
                    int i = 1;
                    while (m_grid[y - i][x].getColor() != color) {
                        m_grid[y - i][x].addToken(player);
                        i++;
                    }
                    break;

                case 2: // diagonale haut droite
                    int i = 1;
                    while (m_grid[y - i][x + i].getColor() != color) {
                        m_grid[y - i][x + i].addToken(player);
                        i++;
                    }
                    break;

                case 3: // vers la droite
                    int i = 1;
                    while (m_grid[y][x + i].getColor() != color) {
                        m_grid[y][x + i].addToken(player);
                        i++;
                    }
                    break;

                case 4: // diagonale bas droite
                    int i = 1;
                    while (m_grid[y + i][x + i].getColor() != color) {
                        m_grid[y + i][x + i].addToken(player);
                        i++;
                    }
                    break;

                case 5: // vers le bas
                    int i = 1;
                    while (m_grid[y + i][x].getColor() != color) {
                        m_grid[y + i][x].addToken(player);
                        i++;
                    }
                    break;

                case 6: // diagonale bas gauche
                    int i = 1;
                    while (m_grid[y + i][x - i].getColor() != color) {
                        m_grid[y + i][x - i].addToken(player);
                        i++;
                    }
                    break;

                case 7: // vers la droite
                    int i = 1;
                    while (m_grid[y][x - i].getColor() != color) {
                        m_grid[y][x - i].addToken(player);
                        i++;
                    }
                    break;

                case 8: // diagonale haut gauche
                    int i = 1;
                    while (m_grid[y - i][x - i].getColor() != color) {
                        m_grid[y - i][x - i].addToken(player);
                        i++;
                    }
                    break;
            }
        }
        return true;
    }
}

void ReversiGrid::addToken(const Player &player)
{
    int x, y;
    do
    {
        x = AskUser::askNumber(m_columns);

        y = AskUser::askNumber(m_lines);
    } while (!isEmptyCell(x, y) && !checkToken(player, x, y));

}