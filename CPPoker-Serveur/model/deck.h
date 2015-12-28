#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include <time.h>
#include <vector>
#include"card.h"

class Deck
{
protected:
    std::vector<Card*> cards;

public:
    Deck();

    void fillWith52Cards();

    Card* randomPick();

    void addCard(Card* card);
};

#endif // DECK_H
