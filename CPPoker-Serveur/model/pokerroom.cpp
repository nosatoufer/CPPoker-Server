#include "pokerroom.h"

PokerRoom::PokerRoom(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlindValue, unsigned int bigBlindValue, std::string name, std::vector<Player*> players) :
    Room(minPlayer, maxPlayer, name, players),
    smallBlindValue(smallBlindValue),
    bigBlindValue(bigBlindValue)
{
    this->game = new PokerGame(this->smallBlindValue, this->bigBlindValue);
}

Game* PokerRoom::startGame() {
    if (!this->checkNumberOfPlayer()) {
        throw RoomException("Nombre de joueur incorrect.");
    }
    if (this->game->getGameState() == GameState::WAITING) {
        for (Player* player : this->players)
            this->game->addPlayer(player);
    } else if (this->game->getGameState() == GameState::OVER) {
        this->game = new PokerGame(this->smallBlindValue, this->bigBlindValue, this->players, 0, this);
    } else {
        throw RoomException("Erreur 01 dans PokerRoom.");
    }
    this->game->startGame();
    return this->game;
}

unsigned int PokerRoom::getSmallBlind() {
    return this->smallBlindValue;
}

unsigned int PokerRoom::getBigBlind() {
    return this->bigBlindValue;
}
