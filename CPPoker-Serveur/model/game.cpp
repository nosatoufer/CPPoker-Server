#include "game.h"

Game::Game(std::vector<Player*> players, Room* room) :
    players(players),
    room(room),
    gameState(GameState::WAITING),
    currentPlayer(0)
{}

void Game::nextPlayer() {
    if (this->gameState != GameState::RUNNING) {
        throw new GameException("Erreur lors du passage au joueur suivant: la partie n'est pas en cours");
    }
    ++this->currentPlayer;
    this->currentPlayer %= players.size();
}

unsigned int Game::getPreviousPlayerId() {
    int previous = static_cast<int>(this->getCurrentPlayerId()-1);
    if (previous == -1) {
        previous = players.size();
    }
    return static_cast<unsigned int>(previous);
}

void Game::setCurrentPlayerId(unsigned int number) {
    if (number >= players.size()) {
        throw new GameException("Le numéro de joueur est supérieur au nombre de joueur.");
    }
    this->currentPlayer = number;
}

Player* Game::getCurrentPlayer() {
    return this->players[this->currentPlayer];
}

unsigned int Game::getCurrentPlayerId() {
    return this->currentPlayer;
}

GameState Game::getGameState() {
    return this->gameState;
}
