#ifndef POKERROOM_H
#define POKERROOM_H

#include <vector>

#include "room.h"
#include "player.h"
#include "pokergame.h"
#include "roomexception.h"

class PokerRoom : public Room
{
protected:
    unsigned int smallBlindValue;
    unsigned int bigBlindValue;

public:
    PokerRoom(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlindValue, unsigned int bigBlindValue, std::string name = "", std::vector<Player*> players = std::vector<Player*>());

    Game* startGame();
};

#endif // POKERROOM_H
