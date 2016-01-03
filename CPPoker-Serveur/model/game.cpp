#include "game.h"

Game::Game(std::vector<Player*> players, Room* room) :
    players(players),
    room(room),
    gameState(GameState::WAITING),
    currentPlayer(0)
{}

void Game::nextPlayer() {
    if (this->gameState != GameState::RUNNING) {
        throw GameException("Erreur lors du passage au joueur suivant: la partie n'est pas en cours");
    }
    ++this->currentPlayer;
    this->currentPlayer %= players.size();
}

void Game::addPlayer(Player* player) {
    this->players.push_back(player);
}

void Game::setCurrentPlayerId(unsigned int number) {
    if (number >= players.size()) {
        throw GameException("Le numéro de joueur est supérieur au nombre de joueur.");
    }
    this->currentPlayer = number;
}

Player* Game::getCurrentPlayer() {
    return this->players[this->currentPlayer];
}

std::vector<Player*> Game::getPlayers() {
    return this->players;
}

unsigned int Game::getCurrentPlayerId() {
    return this->currentPlayer;
}

GameState Game::getGameState() {
    return this->gameState;
}

void Game::cancelGame() {
    this->gameState = GameState::OVER;
}
