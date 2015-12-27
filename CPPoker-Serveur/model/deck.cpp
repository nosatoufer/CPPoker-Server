#include "deck.h"

Deck::Deck() {}

void Deck::fillWith52Cards() {
    for (int i=0; i<13; ++i) {
        for (int j=0; j<4; ++j) {
            cards.push_back(new Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(j)));
        }
    }
}

Card* Deck::randomPick() {
    srand(time(NULL));
    int random = rand() % cards.size();
    Card* card = cards[random];
    cards.erase(cards.begin()+random);
    return card;
}

void Deck::addCard(Card* card) {
    cards.push_back(card);
}
