#ifndef POKERPLAYER_H
#define POKERPLAYER_H

#include "cardplayer.h"

class PokerPlayer : public CardPlayer
{
protected:
    unsigned int currentBet;
    bool isPlayerFold;
public:
    PokerPlayer(std::string nickname, int cash=0);

    void resetCurrentBet();
    unsigned int getCurrentBet();
    unsigned int bet(unsigned int amount);
    void fold();
    void resetFold();
    bool isFold();
};

#endif // POKERPLAYER_H
