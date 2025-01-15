#include "SmallStraight.h"

SmallStraight::SmallStraight(Player* player) : Scorebox(player) {
    this->scoreboxName = "MalyStrit";
}

void SmallStraight::setValue(std::vector<int> dices) {
    bool set = true;

    std::sort(dices.begin(), dices.end(), std::less_equal<int>());

    int unset = 0;
    int prev = 0;
    for(int dice : dices) {
        if(prev == 0) prev = dice;
        else {
            if(dice != prev + 1) {
                unset++;
            }
            prev = dice;
        }
    }

    if(unset > 1) set = false;
    if(set) this->value = 30;
    this->used = true;

    addYatzyValue(dices);
}