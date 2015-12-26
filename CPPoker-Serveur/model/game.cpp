#include "game.h"

Game::Game() {
    this->gameState = GameState::WAITING;
    this->currentPlayer = 0;
}

Game::Game(std::vector<Player*> players) : players(players) {
    this->gameState = GameState::WAITING;
    this->currentPlayer = 0;
    this->room = nullptr;
}

Game::Game(std::vector<Player*> players, Room* room) : players(players), room(room) {
    this->gameState = GameState::WAITING;
    this->currentPlayer = 0;
}

int Game::nextPlayer() {
    if (this->gameState != GameState::RUNNING) {
        throw new GameException("Erreur lors du passage au joueur suivant: la partie n'est pas en cours");
    }
    return ((++this->currentPlayer)%players.size());
}
