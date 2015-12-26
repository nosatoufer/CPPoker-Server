#ifndef POKERROOM_H
#define POKERROOM_H

#include <vector>

#include "room.h"
#include "player.h"
#include "pokergame.h"
#include "roomexception.h"

class PokerRoom : public Room
{
public:
    PokerRoom(int minPlayer, int maxPlayer);

    Game* startGame();
};

#endif // POKERROOM_H
