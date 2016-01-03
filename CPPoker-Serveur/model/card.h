#ifndef CARD_H
#define CARD_H

#include <iostream>

/**
 * @brief The Card class represent a card
 */
class Card
{
public:
    enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, HEIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

protected:
    Rank rank;
    Suit suit;

public:
    Card();
    Card(Rank rank, Suit suit);

    /**
     * @brief getRank return the Rank value of the card
     * @return Rank value of the card
     */
    Rank getRank() const;

    /**
     * @brief getSuit return the Suit value of the card
     * @return Suit value of the card
     */
    Suit getSuit() const;

    /**
     * @brief toString return a string representation of the card
     * @return string format
     */
    std::string toString() const;
};

/**
 * @brief operator << surcharge for Card
 * @param os
 * @param card
 * @return std::ostream with string value of card
 */
std::ostream& operator<<(std::ostream& os, Card card);

/**
 * @brief operator < surcharge for Card
 * @param card1
 * @param card2
 * @return true if card1 < card2, false otherwise
 */
bool operator< (Card const &card1, Card const &card2);

/**
 * @brief operator == surcharge for Card
 * @param card1
 * @param card2
 * @return true if card1.rank == card2.rank
 */
bool operator== (Card const &card1, Card const &card2);

#endif // CARD_H
