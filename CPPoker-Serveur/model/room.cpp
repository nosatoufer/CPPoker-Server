#include "room.h"

Room::Room(unsigned int minPlayer, unsigned int maxPlayer) : minPlayer(minPlayer), maxPlayer(maxPlayer), players(std::vector<Player*>()) {}

void Room::addPlayer(Player* player) {
    players.push_back(player);
}

bool Room::checkNumberOfPlayer() {
    return (players.size() <= maxPlayer && players.size() >= minPlayer);
}
