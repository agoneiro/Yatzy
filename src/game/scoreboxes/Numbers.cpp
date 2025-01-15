#include "Numbers.h"

Numbers::Numbers(Player* player, int number) : Scorebox(player) {
    this->number = number;
    switch(number) {
        case 1:
            this->scoreboxName = "Jedynki";
            break;
        case 2:
            this->scoreboxName = "Dwojki";
            break;
        case 3:
            this->scoreboxName = "Trojki";
            break;
        case 4:
            this->scoreboxName = "Czworki";
            break;
        case 5:
            this->scoreboxName = "Piatki";
            break;
        case 6:
            this->scoreboxName = "Szostki";
            break;
        default: exit(1);
    }
}

void Numbers::setValue(std::vector<int> dices) {
    for(int dice : dices) {
        if(dice == number) value += dice;
    }
    this->used = true;

    addYatzyValue(dices);
}