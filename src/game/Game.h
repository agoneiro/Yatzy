#pragma once

#include "Player.h"
#include "Scorebox.h"
#include <iostream>
#include <vector>

class Game {
private:
    std::vector<Player*> players;
    bool finished = false;
    int roundNumber = 1;

    void initGame();
    void newRound();

    void drawEmptyLine(int columnWidth) const;

    void printTable() const;

    int getColumnWidth() const;

    std::string stringToLower(std::string str) const;

public:
    Game();
    ~Game();

};