#ifndef POKERPLAYER_H
#define POKERPLAYER_H

#include "cardplayer.h"

class PokerPlayer : public CardPlayer
{
protected:
    unsigned int currentBet; // Mise du tour actuel
    unsigned int totalBet; // Montant misé depuis le début d'une partie

    bool fold; // Le joueur est-il couché
    bool allIn; // Le joueur est-il parti en all-in

public:
    PokerPlayer(std::string nickname, int cash=0);
    PokerPlayer(Player* player);

    unsigned int bet(unsigned int amount);
    void resetCurrentBet();
    unsigned int getCurrentBet();
    void reduceBetTo(unsigned int amount);

    void setFold(bool value);
    bool isFold();

    void setAllIn(bool value);
    bool isAllIn();

    void resetTotalBet();
    unsigned int getTotalBet();
};

#endif // POKERPLAYER_H
