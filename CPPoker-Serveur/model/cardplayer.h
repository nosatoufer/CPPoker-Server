#ifndef CARDPLAYER_H
#define CARDPLAYER_H

#include <vector>

#include "player.h"
#include "card.h"

class CardPlayer : public Player
{
protected:
    std::vector<Card*> hand;

public:
    CardPlayer(std::string nickname, int cash=0);

    std::vector<Card*> getHand();
    void addCard(Card* card);
};

#endif // CARDPLAYER_H
