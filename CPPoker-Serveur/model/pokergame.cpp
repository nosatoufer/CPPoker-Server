#include "pokergame.h"

PokerGame::PokerGame() : playerCard(std::vector<Card*[2]>()), playerBet(std::vector<int>()), centralBet(0), dealer(0) {}

PokerGame::PokerGame(std::vector<Player*> players, unsigned int dealer) : Game(players), playerBet(std::vector<int>()), centralBet(0), dealer(dealer) {}

PokerGame::PokerGame(std::vector<Player*> players, unsigned int dealer, Room* room) : Game(players, room), playerBet(std::vector<int>()), centralBet(0), dealer(dealer) {}

void PokerGame::startGame() {
    if (dealer >= players.size()) {
        throw new GameException("L'id du dealer est incorrect.");
    }

    if (players.size() < 2 && players.size() >10){
        throw new GameException("Le nombre de joueur est incorrect.");
    }

    currentPlayer = dealer;
    this->nextPlayer();

    deck = Deck();
    deck.fillWith52Cards();

    for (unsigned i=0; i<players.size(); ++i) {
        playerBet.push_back(0);
        for (unsigned j=0; j<2; ++j) {
            playerCard[i][j] = deck.randomPick();
        }
    }
}
