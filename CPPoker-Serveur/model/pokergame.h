#ifndef POKERGAME_H
#define POKERGAME_H

#include "card.h"
#include "gameexception.h"
#include "deck.h"
#include "pokerplayer.h"
#include "gamestate.h"

class PokerGame
{
protected:
    std::vector<Card*> tableCard;

    Deck deck;
    std::vector<PokerPlayer*> players;

    GameState gameState;

    unsigned int currentPlayer;

    unsigned int minPlayer;
    unsigned int maxPlayer;
    unsigned int dealer; // Id du dealer
    unsigned int smallBlindValue; // Id small blind
    unsigned int bigBlindValue; // Id big blind
    unsigned int round; // Id round (1 -> 4); 5 = fini
    unsigned int biggestBet; // Utile pour vérifier que les joueurs s'alignent sur la même mise à chaque tour
    unsigned int numberOfTurn; // Utile pour vérifier la fin d'un round : il faut que chaque joueur aie joué une fois (check ou bet) et qu'ils aient tous la même mise
    unsigned int pot; // Contient le montant total mis en jeu

public:
    PokerGame(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlindValue = 0, unsigned int bigBlindValue = 0, std::vector<PokerPlayer*> players = std::vector<PokerPlayer*>(), unsigned int dealer = 0);

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
