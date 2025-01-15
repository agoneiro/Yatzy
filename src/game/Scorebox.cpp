#include "Scorebox.h"
#include "Player.h"

Scorebox::Scorebox(Player* player) : player(player){

}

void Scorebox::addYatzyValue(std::vector<int> dices) {
    bool setYatzy = false;

    for(int i = 0; i < dices.size(); i++) {
        int repeated = 0;
        for(int j = 0; j < dices.size(); j++) {
            if(dices[i] == dices[j]) repeated++;
        }
        if(repeated == dices.size()) setYatzy = true;
    }

    if(setYatzy) {
        if(player->isYatzy()) {
            this->value += 50;
        }
        else {
            player->setYatzy(true);
        }
    }
}

int Scorebox::getValue() const {
    return this->value;
}
std::string Scorebox::getScoreboxName() const {
    return this->scoreboxName;
}

bool Scorebox::isUsed() const {
    return this->used;
}