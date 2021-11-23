#include <iostream>

#include "Games/GameReversi.h"
#include "Games/GameLine.h"
#include "Grids/TicTacToe/TicTacToeGrid.h"
#include "Grids/Connect4/Connect4Grid.h"
#include "Grids/Reversi/ReversiGrid.h"
#include "Utils/AskUser.h"

int main()
{
    int choice;
    do
    {
        std::cout << "1-TicTacToe" << std::endl << "2-Connect 4" << std::endl << "3-Reversi" << std::endl;
        std::cout << "Veuillez choisir le jeu de votre choix (1, 2 ou 3)" << std::endl;
        choice = AskUser::askNumber(3);
    } while(choice < 0);

    if(choice == 0)
    {
        TicTacToeGrid grid = TicTacToeGrid();
        GameLine game = GameLine(grid);
        game.start();
    }
    else if(choice == 1)
    {
        Connect4Grid grid = Connect4Grid();
        GameLine game = GameLine(grid);
        game.start();
    }
    else if(choice == 2)
    {
        GameReversi game = GameReversi();
        game.start();
    }

    std::cout << "Au revoir !" << std::endl;
    return 0;
}
