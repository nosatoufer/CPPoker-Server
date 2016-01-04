#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include <time.h>
#include <vector>
#include"card.h"

/**
 * @brief The Deck class represent a deck, a vector of Card
 */
class Deck
{
protected:
    std::vector<Card*> m_cards;

public:
    Deck();

    /**
     * @brief fillWith52Cards fill the deck with a 52 classic french card game
     */
    void fillWith52Cards();

    /**
     * @brief randomPick pick a card from the deck, delete it from the deck and return a pointer to it
     * @return Card pointer
     */
    Card* randomPick();

    /**
     * @brief addCard add the given card to the deck
     * @param card pointer
     */
    void addCard(Card* card);
};

#endif // DECK_H
