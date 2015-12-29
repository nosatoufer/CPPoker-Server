#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card
{
public:
    enum Rank {ACE, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, HEIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

protected:
    Rank rank;
    Suit suit;

public:
    Card();
    Card(Rank rank, Suit suit);

    Rank getRank() const;
    Suit getSuit() const;
};

std::ostream& operator<<(std::ostream& os, Card card);
bool operator< (Card const &card1, Card const &card2);
bool operator== (Card const &card1, Card const &card2);

#endif // CARD_H
