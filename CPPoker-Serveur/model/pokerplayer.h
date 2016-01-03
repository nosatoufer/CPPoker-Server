#ifndef POKERPLAYER_H
#define POKERPLAYER_H

#include <vector>
#include <string>

#include "card.h"
#include "playerexception.h"

class PokerPlayer
{
protected:
    std::string m_nickname;
    int m_cash;
    std::vector<Card*> m_hand;
    unsigned int m_currentBet; // Mise du tour actuel
    unsigned int m_totalBet; // Montant misé depuis le début d'une partie

    bool m_fold; // Le joueur est-il couché
    bool m_allIn; // Le joueur est-il parti en all-in

public:
    PokerPlayer(std::string m_nickname, int m_cash=0);

    int getCash();
    void setCash(int m_cash);

    std::string getNickname();
    void setNickname(std::string m_nickname);

    std::vector<Card*> getHand();
    void addCard(Card* card);

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
