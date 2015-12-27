#include "cardplayer.h"

CardPlayer::CardPlayer(std::string nickname, int cash) :
    Player(nickname, cash)
{}


std::vector<Card*> CardPlayer::getHand() {
    return this->hand;
}

void CardPlayer::addCard(Card* card) {
    this->hand.push_back(card);
}
