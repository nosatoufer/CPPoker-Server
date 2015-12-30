#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "player.h"
#include "game.h"
#include "../controller/modelcontroller.h"

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

    ModelController* controller;

public:
    Room(unsigned int minPlayer, unsigned int maxPlayer, std::string name = "", std::vector<Player*> players = std::vector<Player*>());

    void addPlayer(Player* player);

    virtual Game* startGame() = 0;

    bool checkNumberOfPlayer();

    void attachController(ModelController* controller);
};

#endif // ROOM_H
