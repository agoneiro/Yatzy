#pragma once

#include "../Scorebox.h"

class Chance : public Scorebox {
public:
    Chance(Player* player);

    void setValue(std::vector<int> dices) override;

};