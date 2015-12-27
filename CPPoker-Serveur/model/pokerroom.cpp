#include "pokerroom.h"

PokerRoom::PokerRoom(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlindValue, unsigned int bigBlindValue, std::string name, std::vector<Player*> players) :
    Room(minPlayer, maxPlayer, name, players),
    smallBlindValue(smallBlindValue),
    bigBlindValue(bigBlindValue)
{}

Game* PokerRoom::startGame() {
    if (!this->checkNumberOfPlayer()) {
        throw new RoomException("Nombre de joueur incorrect.");
    }
    Game* pokerGame = new PokerGame(this->smallBlindValue, this->bigBlindValue, this->players, 0, this);
    pokerGame->startGame();
    return pokerGame;
}
