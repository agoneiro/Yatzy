#pragma once

#include "../Scorebox.h"

class Yatzy : public Scorebox {
public:
    Yatzy(Player* player);

    void setValue(std::vector<int> dices) override;

};