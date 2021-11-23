//
// Created by ben on 21/11/2021.
//

#include "Grids/Grid.h"

#ifndef TP3_REVERSIGRID_H
#define TP3_REVERSIGRID_H

class ReversiGrid : public Grid
{
public:
    ReversiGrid();

    void initArray() override;

    void addToken(const Player& player) override;

    bool checkFlipToken(const Player& player, int x, int y, int xModifier, int yModifier, bool first, bool flipMode);

    bool checkFlipToken(const Player& player, int x, int y, bool flipMode);

    bool isWinner(const Player& player) override;

    bool canPlay(const Player& player);

    void setColors(char color1, char color2);

    void getScores(int& scorePlayer1, int& scorePlayer2, int& scoreNeutral);
private:
    char m_colorPlayer1;
    char m_colorPlayer2;
};
#endif //TP3_REVERSIGRID_H