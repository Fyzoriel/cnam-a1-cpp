//
// Created by Fyzoriel on 25/10/2021.
//

#include "Cell.h"

/**
 * Check if cell is empty
 * @return true if cell is empty
 */
bool Cell::isEmpty() const
{
    return value == ' ';
}

void Cell::setColor(char color)
{
    value = color;
}

char Cell::getColor() const
{
    return value;
}
