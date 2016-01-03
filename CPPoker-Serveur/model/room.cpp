#include "room.h"

Room::Room(unsigned int minPlayer, unsigned int maxPlayer, std::string name, std::vector<Player*> players) :
    minPlayer(minPlayer),
    maxPlayer(maxPlayer),
    name(name),
    players(players)
{}

void Room::addPlayer(Player* player) {
    players.push_back(player);
}

bool Room::checkNumberOfPlayer() {
    return (players.size() <= maxPlayer && players.size() >= minPlayer);
}

/*void Room::attachController(ModelController* controller) {
    this->controller = controller;
}*/

unsigned int Room::getMinPlayer() {
    return this->minPlayer;
}

unsigned int Room::getMaxPlayer() {
    return this->maxPlayer;
}

bool Room::readyToStart() {
    if (game->getGameState() == GameState::WAITING || game->getGameState() == GameState::OVER) {
        return (this->players.size() <= maxPlayer && this->players.size() >= minPlayer);
    } else {
        return false;
    }
}

Game* Room::getGame() {
    return this->game;
}

void Room::cancelGame() {
    this->game->cancelGame();
}
