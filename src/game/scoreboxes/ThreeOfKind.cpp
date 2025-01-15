#include "ThreeOfKind.h"

ThreeOfKind::ThreeOfKind(Player* player) : Scorebox(player) {
    this->scoreboxName = "Potrojne";
}

void ThreeOfKind::setValue(std::vector<int> dices) {
    bool set = false;
    int poss_value = 0;
    for(int dice : dices) {
        poss_value += dice;
    }

    for(int i = 0; i < dices.size(); i++) {
        int repeated = 0;
        for(int j = 0; j < dices.size(); j++) {
            if(dices[i] == dices[j]) repeated++;
        }
        if(repeated >= 3) set = true;
    }

    if(set) {
        value = poss_value;
    }
    this->used = true;

    addYatzyValue(dices);
}