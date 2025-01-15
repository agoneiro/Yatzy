#include "Player.h"
#include "scoreboxes/Numbers.h"
#include "scoreboxes/ThreeOfKind.h"
#include "scoreboxes/FourOfKind.h"
#include "scoreboxes/SmallStraight.h"
#include "scoreboxes/LargeStraight.h"
#include "scoreboxes/FullHouse.h"
#include "scoreboxes/Chance.h"
#include "scoreboxes/Yatzy.h"

Player::Player(std::string playerName) {
    this->playerName = playerName;
    scoreboxes.push_back(new Numbers(this, 1));
    scoreboxes.push_back(new Numbers(this, 2));
    scoreboxes.push_back(new Numbers(this, 3));
    scoreboxes.push_back(new Numbers(this, 4));
    scoreboxes.push_back(new Numbers(this, 5));
    scoreboxes.push_back(new Numbers(this, 6));
    scoreboxes.push_back(new ThreeOfKind(this));
    scoreboxes.push_back(new FourOfKind(this));
    scoreboxes.push_back(new SmallStraight(this));
    scoreboxes.push_back(new LargeStraight(this));
    scoreboxes.push_back(new FullHouse(this));
    scoreboxes.push_back(new Chance(this));
    scoreboxes.push_back(new Yatzy(this));
}

void Player::setPlayerName(std::string playerName) {
    this->playerName = playerName;
}
std::string Player::getPlayerName() const {
    return this->playerName;
}

int Player::countTotal() {
    this->total = 0;
    this->total_upper = 0;
    for(Scorebox* scorebox : scoreboxes) {
        this->total += scorebox->getValue();
        if(dynamic_cast<Numbers*>(scorebox)) {
            this->total_upper += scorebox->getValue();
            if(scorebox->getValue() >= 50) {
                this->total_upper -= 50;
            }
        }
    }
    if(this->total_upper >= 63) {
        this->total += 35;
    }
    return this->total;
}

int Player::countTotalUpper() {
    countTotal();
    return this->total_upper;
}

void Player::setYatzy(bool yatzy) {
    this->yatzy = yatzy;
}
bool Player::isYatzy() const {
    return this->yatzy;
}

std::vector<Scorebox*> Player::getScoreboxes() {
    return this->scoreboxes;
}

Player::~Player() {
    for(Scorebox* scorebox : scoreboxes) {
        delete scorebox;
    }
}