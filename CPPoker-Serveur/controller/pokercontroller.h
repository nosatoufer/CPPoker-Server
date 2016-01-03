#ifndef POKERCONTROLLER_H
#define POKERCONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"
#include "../model/pokergame.h"
#include "../pattern/observer.h"

class PokerController : public Observer
{
protected:
    PokerGame* game;

public:
    PokerController(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind);
    virtual ~PokerController();

    // Méthode de jeu
    bool allIn(std::string name);
    bool bet(std::string name, unsigned int value);
    bool fold(std::string name);
    bool check(std::string name);
    bool isPlayerInGame(std::string nickname);

    // Ajouter un player-
    bool addPlayer(std::string name);

    bool readyToStart();
    void startGame();
    void cancelGame();
    bool isGameStarted();
    std::string getCurrentPlayerNickname();
    std::pair<std::string, std::string> getPlayerCards(std::string nickname);

    unsigned int getMinPlayer();
    unsigned int getMaxPlayer();
    unsigned int getSmallBlind();
    unsigned int getBigBlind();

    void update();
};

#endif // POKERCONTROLLER_H
