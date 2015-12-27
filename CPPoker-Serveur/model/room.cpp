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
