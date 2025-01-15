#pragma once

#include "../Scorebox.h"

class FullHouse : public Scorebox {
public:
    FullHouse(Player* player);

    void setValue(std::vector<int> dices) override;

};