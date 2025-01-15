#pragma once

#include "../Scorebox.h"

class FourOfKind : public Scorebox {
public:
    FourOfKind(Player* player);

    void setValue(std::vector<int> dices) override;

};