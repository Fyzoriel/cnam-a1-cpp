#include <iostream>
#include "Game.h"
#include "Connect4Grid.h"

int main()
{

    Game game = Game(new Connect4Grid());
    //Game game = Game(new TicTacToeGrid());

    std::cout << "Au revoir !" << std::endl;
    return 0;
}
