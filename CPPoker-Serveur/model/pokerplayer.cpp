#include "pokerplayer.h"

PokerPlayer::PokerPlayer(std::string nickname, int cash) :
    m_nickname(nickname),
    m_cash(cash),
    m_hand(),
    m_currentBet(0),
    m_totalBet(0),
    m_fold(false),
    m_allIn(false)
{}

int PokerPlayer::getCash() {
    return this->m_cash;
}

void PokerPlayer::setCash(int cash) {
    this->m_cash = cash;
}

std::string PokerPlayer::getNickname() {
    return this->m_nickname;
}

void PokerPlayer::setNickname(std::string nickname) {
    this->m_nickname = nickname;
}

std::vector<Card*> PokerPlayer::getHand() {
    return this->m_hand;
}

void PokerPlayer::addCard(Card* card) {
    this->m_hand.push_back(card);
}


void PokerPlayer::resetCurrentBet() {
    this->m_totalBet += m_currentBet;
    this->m_currentBet = 0;
}

unsigned int PokerPlayer::getCurrentBet() {
    return this->m_currentBet;
}

void PokerPlayer::reduceBetTo(unsigned int amount) {
    if (this->m_currentBet < amount) {
        throw PlayerException("Impossible de ''réduire'' la mise à une valeur supérieure à la somme déjà misée.");
    }
    this->m_cash += (this->m_currentBet-amount);
    this->m_currentBet = amount;
}

unsigned int PokerPlayer::bet(unsigned int amount) {
    if (amount > m_cash) {
        throw PlayerException("Les liquidités sont insuffisantes pour parier un tel montant.");
    }
    this->m_currentBet += amount;
    this->m_cash -= amount;
    return this->m_currentBet;
}

void PokerPlayer::setFold(bool value) {
    this->m_fold = value;
}

bool PokerPlayer::isFold() {
    return this->m_fold;
}

void PokerPlayer::setAllIn(bool value) {
    this->m_allIn = value;
}

bool PokerPlayer::isAllIn() {
    return this->m_allIn;
}

void PokerPlayer::resetTotalBet() {
    this->m_totalBet = 0;
}

unsigned int PokerPlayer::getTotalBet() {
    return this->m_totalBet;
}
