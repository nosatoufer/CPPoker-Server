#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.h"
#include "room.h"
#include "gamestate.h"
#include "gameexception.h"

class Room;

class Game
{
protected:
    std::vector<Player*> players;

    Room* room;

    int currentPlayer;

    GameState gameState;

public:
    Game();
    Game(std::vector<Player*> players);
    Game(std::vector<Player*> players, Room* room);

    virtual void startGame() = 0;

    virtual int nextPlayer();
};

#endif // GAME_H
