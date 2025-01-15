#include "LargeStraight.h"

LargeStraight::LargeStraight(Player* player) : Scorebox(player) {
    this->scoreboxName = "DuzyStrit";
}

void LargeStraight::setValue(std::vector<int> dices) {
    bool set = true;

    std::sort(dices.begin(), dices.end(), std::less_equal<int>());

    int prev = 0;
    for(int dice : dices) {
        if(prev == 0) prev = dice;
        else {
            if(dice != prev + 1) {
                set = false;
            }
            prev = dice;
        }
    }

    if(set) this->value = 40;
    this->used = true;

    addYatzyValue(dices);
}