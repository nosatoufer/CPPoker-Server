#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "player.h"
#include "game.h"

class Game;

class Room
{
protected:
    unsigned int minPlayer;
    unsigned int maxPlayer;

    std::vector<Player*> players;

    Game* game;

public:
    Room();
    Room(unsigned int minPlayer, unsigned int maxPlayer);

    void addPlayer(Player* player);

    virtual Game* startGame() = 0;

    bool checkNumberOfPlayer();
};

#endif // ROOM_H
