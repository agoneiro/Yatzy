#pragma once

#include "../Scorebox.h"

class ThreeOfKind : public Scorebox {
public:
    ThreeOfKind(Player* player);

    void setValue(std::vector<int> dices) override;

};