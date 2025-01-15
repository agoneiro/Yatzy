#pragma once

#include "../Scorebox.h"
#include <algorithm>

class LargeStraight : public Scorebox {
public:
    LargeStraight(Player* player);

    void setValue(std::vector<int> dices) override;

};