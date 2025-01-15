#pragma once

#include "Scorebox.h"
#include <iostream>
#include <vector>

class Player {
private:
    std::string playerName;
    std::vector<Scorebox*> scoreboxes;
    int total = 0;
    int total_upper = 0;
    bool yatzy = false;

public:
    Player(std::string playerName);

    void setPlayerName(std::string playerName);
    std::string getPlayerName() const;

    int countTotal();
    int countTotalUpper();

    void setYatzy(bool isYatzy);
    bool isYatzy() const;


    std::vector<Scorebox*> getScoreboxes();

    ~Player();
};