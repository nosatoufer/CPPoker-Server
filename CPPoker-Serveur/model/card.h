#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
public:
    enum Rank {ACE, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, HEIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

    Card();
    Card(Rank rank, Suit suit);

    Rank getRank();
    Suit getSuit();

protected:
    Rank rank;
    Suit suit;
};

std::ostream& operator<<(std::ostream& os, Card card);

#endif // CARD_H
