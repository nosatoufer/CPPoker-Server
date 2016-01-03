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

    GameState gameState;

    unsigned int currentPlayer;

public:
    Game(std::vector<Player*> players = std::vector<Player*>(), Room* room = nullptr);

    virtual void startGame() = 0;

    virtual void nextPlayer();

    virtual void setCurrentPlayerId(unsigned int number);

    virtual Player* getCurrentPlayer();
    virtual std::vector<Player*> getPlayers();
    virtual unsigned int getCurrentPlayerId();

    virtual GameState getGameState();
    void cancelGame();
    void addPlayer(Player* player);
};

#endif // GAME_H
