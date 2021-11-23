//
// Created by Fyzoriel on 25/10/2021.
//

#include "Cell.h"

bool Cell::isEmpty() const
{
    return value == ' ';
}

void Cell::setColor(char color)
{
    value = color;
}

char Cell::getColor() {
    return value;
}
