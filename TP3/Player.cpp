//
// Created by Fyzoriel on 25/10/2021.
//

#include "Player.h"

/* Public methods */
Player::Player() : Player('E') {}
Player::Player(char color): m_color(color) {}

char Player::getColor() const {
    return m_color;
}
