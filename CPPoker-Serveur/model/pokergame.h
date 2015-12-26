#ifndef POKERGAME_H
#define POKERGAME_H

#include "game.h"
#include "card.h"
#include "gameexception.h"
#include "deck.h"

class PokerGame : public Game
{
protected:
    std::vector<Card*[2]> playerCard;
    std::vector<int> playerBet;
    Card* tableCard[5];

    Deck deck;

    unsigned int centralBet;
    unsigned int dealer;

public:
    PokerGame();
    PokerGame(std::vector<Player*> players, unsigned int dealer);
    PokerGame(std::vector<Player*> players, unsigned int dealer, Room* room);

    void startGame();
};

#endif // POKERGAME_H
