//
// Created by ben on 21/11/2021.
//

#ifndef TP3_REVERSIGRID_H
#define TP3_REVERSIGRID_H

#endif //TP3_REVERSIGRID_H

class ReversiGrid : public Grid
{
public:
    ReversiGrid();

    bool verifToken(const Player &player, int x, int y);
    bool addToken(const Player &player, int x, int y) override;

};