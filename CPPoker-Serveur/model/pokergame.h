#ifndef POKERGAME_H
#define POKERGAME_H

#include "card.h"
#include "gameexception.h"
#include "deck.h"
#include "pokerplayer.h"
#include "gamestate.h"
#include "../pattern/subject.h"

/**
 * @brief The PokerGame class represent a Texas hold'em poker game with small blind et big blind
 */
class PokerGame
{
protected:
    std::vector<PokerPlayer*> m_players;
    std::vector<Card*> m_tableCard;
    Deck m_deck;
    GameState m_gameState;
    unsigned int m_currentPlayer;
    unsigned int m_minPlayer;
    unsigned int m_maxPlayer;
    unsigned int m_dealerId;
    unsigned int m_smallBlindValue;
    unsigned int m_bigBlindValue;
    unsigned int m_round;
    unsigned int m_biggestBet;
    unsigned int m_numberOfTurn;
    unsigned int m_pot;

public:
    PokerGame(unsigned int m_minPlayer, unsigned int m_maxPlayer, unsigned int m_smallBlindValue = 0, unsigned int m_bigBlindValue = 0, std::vector<PokerPlayer*> players = std::vector<PokerPlayer*>(), unsigned int m_dealerId = 0);

    virtual ~PokerGame();

    // Méthodes de jeu
    /**
     * @brief startGame start the game if the number of player is correct
     */
    virtual void startGame();
    /**
     * @brief bet is a player action to bet a certain amount, it must fit the texas hold'em poker rules
     * @param amount of the bet
     */
    virtual void bet(unsigned int amount);
    /**
     * @brief fold is a player action to give up the current hand
     */
    virtual void fold();
    /**
     * @brief check is a player action for not betting (only in a few case, see texas hold'em poker rules)
     */
    virtual void check();
    /**
     * @brief allIn is a player action for betting all his money (only in a few case, see texas hold'em poker rules)
     */
    virtual void allIn();
    /**
     * @brief cancelGame end the game with no winners
     */
    void cancelGame();

    // Méthodes utilitaires
    /**
     * @brief setCurrentPlayerId set the current player to the given id
     * @param number is the id of the new current player
     */
    virtual void setCurrentPlayerId(unsigned int number);
    /**
     * @brief addPlayer add a player to the game (only if game not running)
     * @param player pointeur to add to the game
     */
    void addPlayer(PokerPlayer* player);
    /**
     * @brief getPlayer return the PokerPlayer
     * @param nickname
     * @return
     */
    virtual PokerPlayer* getPlayer(std::string nickname);
    /**
     * @brief readyToStart check if the game is ready to start (good number of player and game not running)
     * @return true if game is ready to start, false otherwise
     */
    virtual bool readyToStart();
    /**
     * @brief nextPlayer switch to the next player
     */
    virtual void nextPlayer();
    /**
     * @brief numberOfActivePlayer return the number of active player (all-in or fold player ar inactive)
     * @return number of active player
     */
    virtual unsigned int numberOfActivePlayer();
    /**
     * @brief isRoundOver check if the round is over (everybody on the same bet)
     * @return true if round is over, false otherwise
     */
    virtual bool isRoundOver();
    /**
     * @brief getNextPlayerId return the next player id
     * @return next player id
     */
    unsigned int getNextPlayerId();
    /**
     * @brief putBetsInPot put the bet of all player in the central pot of the table
     */
    void putBetsInPot();

    // Méthodes d'accès
    /**
     * @brief getGameState return the current game state
     * @return game state
     */
    virtual GameState getGameState();
    /**
     * @brief getTableCard return the card of the table
     * @return vector of card present on the table
     */
    std::vector<Card*> getTableCard();
    /**
     * @brief getMinPlayer return the minimum player value
     * @return minimum player value
     */
    unsigned int getMinPlayer();
    /**
     * @brief getMaxPlayer return the maximum player value
     * @return maximum player value
     */
    unsigned int getMaxPlayer();
    /**
     * @brief getSmallBlind return the small blind value
     * @return small blind value
     */
    unsigned int getSmallBlind();
    /**
     * @brief getBigBlind return the big blind value
     * @return big blind value
     */
    unsigned int getBigBlind();
    /**
     * @brief getRound return the round number
     * @return round number
     */
    virtual unsigned int getRound();
    /**
     * @brief getCurrentPlayerId return the current player id
     * @return current player id
     */
    virtual unsigned int getCurrentPlayerId();
    /**
     * @brief getCurrentPlayerNickname return the current player nickname
     * @return current player nickname
     */
    virtual std::string getCurrentPlayerNickname();
    /**
     * @brief getCurrentPlayer return a pointer to the current PokerPlayer
     * @return pointer to the current pokerPlayer
     */
    virtual PokerPlayer* getCurrentPlayer();
    /**
     * @brief getPlayers return a vector of pointer to the players of the game
     * @return vector of pointer to players of the game
     */
    virtual std::vector<PokerPlayer*> getPlayers();

};

#endif // POKERGAME_H
