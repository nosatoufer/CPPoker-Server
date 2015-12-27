#include "pokerplayer.h"

PokerPlayer::PokerPlayer(std::string nickname, int cash) :
    CardPlayer(nickname, cash),
    currentBet(0)
{}

void PokerPlayer::resetCurrentBet() {
    this->currentBet = 0;
}

unsigned int PokerPlayer::getCurrentBet() {
    return this->currentBet;
}

unsigned int PokerPlayer::bet(unsigned int amount) {
    if (amount > cash) {
        throw new PlayerException("Les liquidités sont insuffisantes pour parier un tel montant.");
    }
    this->currentBet += amount;
    this->cash -= amount;
    return this->currentBet;
}

void PokerPlayer::fold() {
    this->isPlayerFold = true;
}

void PokerPlayer::resetFold() {
    this->isPlayerFold = false;
}

bool PokerPlayer::isFold() {
    return this->isPlayerFold;
}
