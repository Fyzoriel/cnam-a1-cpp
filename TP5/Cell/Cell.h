//
// Created by Fyzoriel on 25/10/2021.
//

#ifndef TP3_CELL_H
#define TP3_CELL_H


#include "Player.h"

class Cell
{

public:
    bool isEmpty() const;
    void setColor(char color);
    char getColor();

private:
    char value = ' ';

};


#endif //TP3_CELL_H
