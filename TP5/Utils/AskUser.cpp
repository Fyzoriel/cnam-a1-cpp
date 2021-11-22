//
// Created by Fyzoriel on 22/11/2021.
//

#include <iostream>
#include "AskUser.h"
int AskUser::askNumber(int max)
{
    int ask;
    bool retry;
    do
    {
        std::cin >> ask;
        std::cin.clear();
        std::cin.ignore();
        retry = std::cin.fail() || ask < 1 || ask > max;
        if (retry)
        {
            std::cout << std::endl << "You have to enter a valid number: " << std::endl;
        }
    } while (retry);

    return ask-1;
}