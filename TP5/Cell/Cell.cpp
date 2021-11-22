//
// Created by Fyzoriel on 25/10/2021.
//

#include "Cell.h"

bool Cell::isEmpty() const
{
    return value == ' ';
}

void Cell::addToken(const Player &player)
{
    value = player.getColor();
}

char Cell::getColor() {
    return value;
}
