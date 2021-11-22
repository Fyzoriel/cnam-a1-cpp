#include <iostream>
#include "Grids/TicTacToe/TicTacToeGrid.h"
#include "Game.h"
#include "Grids/Connect4/Connect4Grid.h"
#include "Grids/Reversi/ReversiGrid.h"

using namespace std;
int main()
{
    int choice;
    do
    {
        cout << "1-TicTacToe" << endl << "2-Connect 4" << endl << "3-Reversi" << endl;
        cout << "Veuillez choisir le jeu de votre choix (1, 2 ou 3)" << std::endl;
        cin >> choice;
    } while(choice < 1 || choice > 3);

    if(choice == 1)
    {
        TicTacToeGrid grid = TicTacToeGrid();
        Game game = Game(grid);
    }
    else if(choice == 2)
    {
        Connect4Grid grid = Connect4Grid();
        Game game = Game(grid);
    }
    else if(choice == 3)
    {
        ReversiGrid grid = ReversiGrid();
        Game game = Game(grid);
    }

    std::cout << "Au revoir !" << std::endl;
    return 0;
}
