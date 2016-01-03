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
    unsigned int m_cash;
    std::vector<Card*> m_hand;
    unsigned int m_currentBet; // Mise du tour actuel
    unsigned int m_totalBet; // Montant misé depuis le début d'une partie

    bool m_fold; // Le joueur est-il couché
    bool m_allIn; // Le joueur est-il parti en all-in

public:
    PokerPlayer(std::string m_nickname, int m_cash=0);

    /**
     * @brief getCash return the cash of the player
     * @return cash value
     */
    int getCash();
    /**
     * @brief setCash set the cash value of the player to a certain amount
     * @param m_cash is tha mount of cash
     */
    void setCash(int m_cash);

    /**
     * @brief getNickname return the nickname of the player
     * @return nickname of the player
     */
    std::string getNickname();
    /**
     * @brief setNickname set the nickname of the player
     * @param m_nickname of the player
     */
    void setNickname(std::string m_nickname);

    /**
     * @brief getHand return the hand (cards) of the player
     * @return vector of hand pointer
     */
    std::vector<Card*> getHand();
    /**
     * @brief addCard add a card to the hand of the player
     * @param card pointer
     */
    void addCard(Card* card);

    /**
     * @brief bet update the current bet amount of the player
     * @param amount of the bet
     * @return
     */
    unsigned int bet(unsigned int amount);
    /**
     * @brief resetCurrentBet reset the current bet of the player and increase the amount of his totalBet
     */
    void resetCurrentBet();
    /**
     * @brief getCurrentBet return the value of the current bet
     * @return value of the current bet
     */
    unsigned int getCurrentBet();
    /**
     * @brief reduceBetTo reduce the current player bet to the amount given
     * @param amount to reduce the bet to
     */
    void reduceBetTo(unsigned int amount);

    /**
     * @brief setFold change the fold value of the player
     * @param value of the bool
     */
    void setFold(bool value);
    /**
     * @brief isFold check if the player is fold or not
     * @return true if player is fold, false otherwise
     */
    bool isFold();

    /**
     * @brief setAllIn change the allIn value of the player
     * @param value of the bool
     */
    void setAllIn(bool value);
    /**
     * @brief isAllIn check if the player is all in
     * @return true if player all in, false otherwise
     */
    bool isAllIn();

    /**
     * @brief resetTotalBet reset the total bet
     */
    void resetTotalBet();
    /**
     * @brief getTotalBet return the amount of the total bet
     * @return total bet
     */
    unsigned int getTotalBet();
};

#endif // POKERPLAYER_H
