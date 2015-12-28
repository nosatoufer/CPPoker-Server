#ifndef POKERGAME_H
#define POKERGAME_H

#include "game.h"
#include "card.h"
#include "gameexception.h"
#include "deck.h"
#include "pokerplayer.h"

class PokerGame : public Game
{
protected:
    std::vector<Card*> tableCard;

    Deck deck;

    unsigned int dealer; // Id du dealer
    unsigned int smallBlindValue; // Id small blind
    unsigned int bigBlindValue; // Id big blind
    unsigned int round; // Id round (1 -> 4); 5 = fini
    unsigned int biggestBet; // Utile pour vérifier que les joueurs s'alignent sur la même mise à chaque tour
    unsigned int numberOfTurn; // Utile pour vérifier la fin d'un round : il faut que chaque joueur aie joué une fois (check ou bet) et qu'ils aient tous la même mise
    unsigned int pot; // Contient le montant total mis en jeu

public:
    PokerGame(unsigned int smallBlindValue = 0, unsigned int bigBlindValue = 0, std::vector<Player*> players = std::vector<Player*>(), unsigned int dealer = 0, Room* room = nullptr);

    virtual void startGame();

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
};

#endif // POKERGAME_H
