#include <iostream>
#include "Game.h"
#include "Connect4Grid.h"
using namespace std;
int main()
{
    int choice;
    do
    {
        cout << "1-TicTacToe" << endl << "2-Connect 4" << endl << "3-Reversi" << endl;
        cout << "Veuillez choisir le jeu de votre choix (1, 2 ou 3)";
        cin >> choice;
    } while(choice < 1 || choice > 3);

    if(choice == 1)
    {
        Game game = Game(new TicTacToeGrid());
    }
    else if(choice == 2)
    {
        Game game = Game(new Connect4Grid());
    }
    else if(choice == 3)
    {
        Game game = Game(new ReversiGrid());
    }

    std::cout << "Au revoir !" << std::endl;
    return 0;
}
