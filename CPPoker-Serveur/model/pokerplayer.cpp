#include "pokerplayer.h"

PokerPlayer::PokerPlayer(std::string nickname, int cash) :
    nickname(nickname),
    cash(cash),
    hand(),
    currentBet(0),
    totalBet(0),
    fold(false),
    allIn(false)
{}

int PokerPlayer::getCash() {
    return this->cash;
}

void PokerPlayer::setCash(int cash) {
    this->cash = cash;
}

std::string PokerPlayer::getNickname() {
    return this->nickname;
}

void PokerPlayer::setNickname(std::string nickname) {
    this->nickname = nickname;
}

std::vector<Card*> PokerPlayer::getHand() {
    return this->hand;
}

void PokerPlayer::addCard(Card* card) {
    this->hand.push_back(card);
}


void PokerPlayer::resetCurrentBet() {
    this->totalBet += currentBet;
    this->currentBet = 0;
}

unsigned int PokerPlayer::getCurrentBet() {
    return this->currentBet;
}

void PokerPlayer::reduceBetTo(unsigned int amount) {
    if (this->currentBet < amount) {
        throw PlayerException("Impossible de ''réduire'' la mise à une valeur supérieure à la somme déjà misée.");
    }
    this->cash += (this->currentBet-amount);
    this->currentBet = amount;
}

unsigned int PokerPlayer::bet(unsigned int amount) {
    if (amount > cash) {
        throw PlayerException("Les liquidités sont insuffisantes pour parier un tel montant.");
    }
    this->currentBet += amount;
    this->cash -= amount;
    return this->currentBet;
}

void PokerPlayer::setFold(bool value) {
    this->fold = value;
}

bool PokerPlayer::isFold() {
    return this->fold;
}

void PokerPlayer::setAllIn(bool value) {
    this->allIn = value;
}

bool PokerPlayer::isAllIn() {
    return this->allIn;
}

void PokerPlayer::resetTotalBet() {
    this->totalBet = 0;
}

unsigned int PokerPlayer::getTotalBet() {
    return this->totalBet;
}
