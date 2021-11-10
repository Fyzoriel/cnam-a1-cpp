//
// Created by Fyzoriel on 25/10/2021.
//

#ifndef TP3_PLAYER_H
#define TP3_PLAYER_H


class Player
{

public:
    Player();
    explicit Player(char color);
    char getColor() const;

private:
    char m_color;

};

#endif //TP3_PLAYER_H
