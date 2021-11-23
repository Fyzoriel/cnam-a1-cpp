//
// Created by Fyzoriel on 25/10/2021.
//

#include "Player.h"

Player::Player() : Player('D') {}
Player::Player(char color): m_color(color) {}

char Player::getColor() const
{
    return m_color;
}
