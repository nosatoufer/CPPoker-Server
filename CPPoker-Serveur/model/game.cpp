#include "game.h"

Game::Game(std::vector<Player*> players, Room* room) :
    players(players),
    room(room),
    gameState(GameState::WAITING),
    currentPlayer(0)
{}

