#ifndef POKERCONTROLLER_H
#define POKERCONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"
#include "../model/pokergame.h"

class PokerRoom;

class PokerController
{
protected:
    PokerGame* game;

public:
    PokerController(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind);
    virtual ~PokerController();
    PokerController(PokerRoom* room);

    // TODO :
    // Les différentes option de jeu d'un joueur
    bool allIn(std::string name);
    bool bet(std::string name, unsigned int value);
    bool fold(std::string name);
    bool isPlayerInGame(std::string nickname);

    // Ajoute un player quand la room ajoute un joueur
    bool addPlayer(std::string name);

    bool readyToStart();
    void startGame();
    void cancelGame();
    bool isGameStarted();
    std::pair<std::string, std::string> getPlayerCards(std::string nickname);

    unsigned int getMinPlayer();
    unsigned int getMaxPlayer();
    unsigned int getSmallBlind();
    unsigned int getBigBlind();

    void update();
};

#endif // POKERCONTROLLER_H
