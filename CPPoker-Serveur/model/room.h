#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "player.h"
#include "game.h"

class Game;
class ModelController;

class Room
{
protected:
    unsigned int minPlayer;
    unsigned int maxPlayer;
    std::string name;

    std::vector<Player*> players;

    Game* game;

    //ModelController* controller;

public:
    Room(unsigned int minPlayer, unsigned int maxPlayer, std::string name = "", std::vector<Player*> players = std::vector<Player*>());

    void addPlayer(Player* player);

    virtual Game* startGame() = 0;

    virtual bool checkNumberOfPlayer();

    virtual unsigned int getMinPlayer();

    virtual unsigned int getMaxPlayer();

    virtual bool readyToStart();

    virtual Game* getGame();

    virtual void cancelGame();

    //void attachController(ModelController* controller);
};

#endif // ROOM_H
