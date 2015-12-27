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
    Card* tableCard[5];

    Deck deck;

    unsigned int centralBet;
    unsigned int dealer;
    unsigned int smallBlindValue;
    unsigned int bigBlindValue;
    unsigned int round;
    unsigned int biggestBet; // Utile pour vérifier que les joueurs s'alignent sur la même mise
    unsigned int numberOfTurn; // Utile pour vérifier la fin d'un round : il faut que chaque joueur aie joué une fois (check ou bet) et qu'ils aient tous la même mise

public:
    PokerGame(unsigned int smallBlindValue = 0, unsigned int bigBlindValue = 0, std::vector<Player*> players = std::vector<Player*>(), unsigned int dealer = 0, Room* room = nullptr);

    virtual void nextPlayer();
    virtual void startGame();
    virtual void bet(unsigned int amount);
    virtual void fold();
    virtual void check();
    virtual unsigned int getRound();
    virtual bool isRoundOver();
    unsigned int getNextPlayerId();
};

#endif // POKERGAME_H
