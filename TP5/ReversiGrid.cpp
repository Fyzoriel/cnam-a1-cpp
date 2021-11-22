//
// Created by boybe on 21/11/2021.
//

#include "ReversiGrid.h"
#include "Player.h"

ReversiGrid::ReversiGrid() : Grid(4,7){}

bool ReversiGrid::verifToken(const Player &player, int x, int y)
{
    int direction = 1;
    char color = player.getColor();
    while(direction < 9)
    {
        switch (direction)
        {
            case 1: // vers le haut
                int i = 1;
                if (y >= 2)
                {
                    if (color == Grid[y - i][x].getColor() || Grid[y - i][x].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (Grid[y - i][x].getColor() == ' ')
                                direction++;
                            else if (Grid[y - i][x].getColor() == color)
                                return true;
                        } while (Grid[y - i][x].getColor() != color && Grid[y - i][x].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 2: // diagonale haut droite
                int i = 1;
                if (y >= 2 && x <= 5)
                {
                    if (color == Grid[y - i][x + i].getColor() || Grid[y - i][x + i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (Grid[y - i][x + i].getColor() == ' ')
                                direction++;
                            else if (Grid[y - i][x + i].getColor() == color)
                                return true;
                        } while (Grid[y - i][x + i].getColor() != color && Grid[y - i][x + i].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 3: // vers la droite
                int i = 1;
                if (x <= 5)
                {
                    if (color == Grid[y][x + i].getColor() || Grid[y][x + i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (Grid[y][x + i].getColor() == ' ')
                                direction++;
                            else if (Grid[y][x + i].getColor() == color)
                                return true;
                        } while (Grid[y][x + i].getColor() != color && Grid[y][x + i].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 4: // diagonale bas droite
                int i = 1;
                if (y <= 5 && x <= 5)
                {
                    if (color == Grid[y + i][x + i].getColor() || Grid[y + i][x + i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (Grid[y + i][x + i].getColor() == ' ')
                                direction++;
                            else if (Grid[y + i][x + i].getColor() == color)
                                return true;
                        } while (Grid[y + i][x + i].getColor() != color && Grid[y + i][x + i].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 5: // vers le bas
                int i = 1;
                if (y <= 5)
                {
                    if (color == Grid[y + i][x].getColor() || Grid[y + i][x].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (Grid[y + i][x].getColor() == ' ')
                                direction++;
                            else if (Grid[y + i][x].getColor() == color)
                                return true;
                        } while (Grid[y + i][x].getColor() != color && Grid[y + i][x].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 6: // diagonale bas gauche
                int i = 1;
                if (y <= 5 && x >= 2)
                {
                    if (color == Grid[y + i][x - i].getColor() || Grid[y + i][x - i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (Grid[y + i][x - i].getColor() == ' ')
                                direction++;
                            else if (Grid[y + i][x - i].getColor() == color)
                                return true;
                        } while (Grid[y + i][x - i].getColor() != color && Grid[y + i][x - i].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 7: // vers la gauche
                int i = 1;
                if (x >= 2)
                {
                    if (color == Grid[y][x - i].getColor() || Grid[y][x - i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (Grid[y][x - i].getColor() == ' ')
                                direction++;
                            else if (Grid[y][x - i].getColor() == color)
                                return true;
                        } while (Grid[y][x - i].getColor() != color && Grid[y][x - i].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;

            case 8: // diagonale haut gauche
                int i = 1;
                if (y >= 2 && x >= 2)
                {
                    if (color == Grid[y - i][x - i].getColor() || Grid[y - i][x - i].getColor() == ' ') //avant de débuter la boucle d'après
                        direction++;
                    else
                    {
                        do
                        {
                            i++;
                            if (Grid[y - i][x - i].getColor() == ' ')
                                direction++;
                            else if (Grid[y - i][x - i].getColor() == color)
                                return true;
                        } while (Grid[y - i][x - i].getColor() != color && Grid[y - i][x - i].getColor() != ' ');
                    }
                }
                else
                    direction++;
                break;
        }
    }
}

bool ReversiGrid::addToken(const Player &player, int x, int y)
{
    if(verifToken(player,x,y) == true)
        if (isEmptyCell(x, y))
        {
            m_grid[y][x].addToken(player);
            return true;
        }
    else
        return false;
}