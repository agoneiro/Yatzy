#include "FullHouse.h"

FullHouse::FullHouse(Player* player) : Scorebox(player) {
    this->scoreboxName = "Full";
}

void FullHouse::setValue(std::vector<int> dices) {
    bool set = false;
    int three = 0;
    int two = 0;

    for(int dice : dices) {
        int repeated = 0;
        for(int i = 0; i < dices.size(); i++) {
            if(dice == dices[i]) {
                repeated++;
            }
        }
        if(repeated == 3) three++;
        else if(repeated == 2) two++;
    }
    if(three == 3 && two == 2) {
        set = true;
    }
    if(set) this->value = 25;
    this->used = true;

    addYatzyValue(dices);
}