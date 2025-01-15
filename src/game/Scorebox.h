#pragma once

#include <iostream>
#include <vector>

class Player;

class Scorebox {
protected:
    Player* player = nullptr;

    int value = 0;
    bool used = false;
    std::string scoreboxName;

public:
    Scorebox(Player* player);

    virtual void setValue(std::vector<int> dices) = 0;
    void addYatzyValue(std::vector<int> dices);
    int getValue() const;
    std::string getScoreboxName() const;

    bool isUsed() const;

    virtual ~Scorebox() = default;

};