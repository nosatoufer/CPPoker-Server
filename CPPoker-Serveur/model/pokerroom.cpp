#include "pokerroom.h"

PokerRoom::PokerRoom(int minPlayer, int maxPlayer) : Room(minPlayer, maxPlayer) {}



Game* PokerRoom::startGame() {
    if (!this->checkNumberOfPlayer()) {
        throw new RoomException("Nombre de joueur incorrect.");
    }
    return new PokerGame(this->players, 0, this);
}
