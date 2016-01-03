#ifndef POKERCONTROLLER_H
#define POKERCONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"
#include "../pattern/observer.h"
#include "../model/game.h"
#include "../model/pokerroom.h"

class PokerRoom;

class PokerController : public Observer
{
protected:
    PokerRoom* model;

public:
    PokerController(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind);
    virtual ~PokerController();
    PokerController(PokerRoom* room);

    // TODO :
    // Les différentes option de jeu d'un joueur
    bool allIn(std::string name);
    bool call(std::string name);
    bool check(std::string name);
    bool raise(std::string name);
    bool fold(std::string name);
    bool isPlayerInGame(std::string nickname);

    // Ajoute un player quand la room ajoute un joueur
    bool addPlayer(std::string name);

    bool readyToStart();
    void startGame();
    void cancelGame();

    unsigned int getMinPlayer();
    unsigned int getMaxPlayer();
    unsigned int getSmallBlind();
    unsigned int getBigBlind();

    void update();
};

#endif // POKERCONTROLLER_H
