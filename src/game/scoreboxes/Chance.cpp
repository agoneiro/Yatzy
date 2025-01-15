#include "Chance.h"

Chance::Chance(Player* player) : Scorebox(player) {
    this->scoreboxName = "Szansa";
}

void Chance::setValue(std::vector<int> dices) {
    for(int dice : dices) {
        this->value += dice;
    }
    this->used = true;

    addYatzyValue(dices);
}