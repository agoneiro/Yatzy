#pragma once

#include "../Scorebox.h"
#include <algorithm>

class SmallStraight : public Scorebox {
public:
    SmallStraight(Player* player);

    void setValue(std::vector<int> dices) override;

};