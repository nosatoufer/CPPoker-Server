#ifndef POKERGAME_H
#define POKERGAME_H

#include "card.h"
#include "gameexception.h"
#include "deck.h"
#include "pokerplayer.h"
#include "gamestate.h"
#include "../pattern/subject.h"

class PokerGame : public Subject
{
protected:
    std::vector<PokerPlayer*> m_players;

    std::vector<Card*> m_tableCard;

    Deck m_deck;

    GameState m_gameState;

    unsigned int m_currentPlayer;

    unsigned int m_minPlayer;
    unsigned int m_maxPlayer;
    unsigned int m_dealer;
    unsigned int m_smallBlindValue;
    unsigned int m_bigBlindValue;
    unsigned int m_round;
    unsigned int m_biggestBet;
    unsigned int m_numberOfTurn;
    unsigned int m_pot;

public:
    PokerGame(unsigned int m_minPlayer, unsigned int m_maxPlayer, unsigned int m_smallBlindValue = 0, unsigned int m_bigBlindValue = 0, std::vector<PokerPlayer*> players = std::vector<PokerPlayer*>(), unsigned int m_dealer = 0);

    virtual ~PokerGame();

    virtual void startGame();

    virtual void setCurrentPlayerId(unsigned int number);

    virtual PokerPlayer* getCurrentPlayer();
    virtual std::vector<PokerPlayer*> getPlayers();
    virtual PokerPlayer* getPlayer(std::string nickname);
    virtual unsigned int getCurrentPlayerId();
    virtual std::string getCurrentPlayerNickname();

    virtual bool readyToStart();

    virtual GameState getGameState();
    void cancelGame();
    void addPlayer(PokerPlayer* player);

    // Méthodes d'accès
    std::vector<Card*> getTableCard();

    // Méthodes de jeu
    virtual void bet(unsigned int amount);
    virtual void fold();
    virtual void check();
    virtual void allIn();

    // Méthodes utilitaires
    virtual void nextPlayer();
    virtual unsigned int getRound();
    virtual unsigned int numberOfActivePlayer();
    virtual bool isRoundOver();
    unsigned int getNextPlayerId();
    void putBetsInPot();
    unsigned int getMinPlayer();
    unsigned int getMaxPlayer();
    unsigned int getSmallBlind();
    unsigned int getBigBlind();
};

#endif // POKERGAME_H
