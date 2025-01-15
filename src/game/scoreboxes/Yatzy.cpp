#include "Yatzy.h"

Yatzy::Yatzy(Player* player) : Scorebox(player) {
    this->scoreboxName = "General";
}

void Yatzy::setValue(std::vector<int> dices) {
    bool set = false;

    for(int i = 0; i < dices.size(); i++) {
        int repeated = 0;
        for(int j = 0; j < dices.size(); j++) {
            if(dices[i] == dices[j]) repeated++;
        }
        if(repeated == dices.size()) set = true;
    }

    if(set) {
        value = 50;
    }
    this->used = true;

    addYatzyValue(dices);
}