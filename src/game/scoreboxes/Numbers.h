#pragma once

#include "../Scorebox.h"

class Numbers : public Scorebox {
private:
    int number = 0;

public:
    Numbers(Player* player, int number);

    void setValue(std::vector<int> dices) override;

};