#include "deck.h"

Deck::Deck() {}

void Deck::fillWith52Cards() {
    for (int i=0; i<13; ++i) {
        for (int j=0; j<4; ++j) {
            m_cards.push_back(new Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(j)));
        }
    }
}

Card* Deck::randomPick() {
    srand(time(NULL));
    int random = rand() % m_cards.size();
    Card* card = m_cards[random];
    m_cards.erase(m_cards.begin()+random);
    return card;
}

void Deck::addCard(Card* card) {
    m_cards.push_back(card);
}
