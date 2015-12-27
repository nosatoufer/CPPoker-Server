#include "pokergame.h"

PokerGame::PokerGame(unsigned int smallBlindValue, unsigned int bigBlindValue, std::vector<Player*> players, unsigned int dealer, Room* room) :
    Game(players, room),
    centralBet(0), dealer(dealer),
    smallBlindValue(smallBlindValue),
    bigBlindValue(bigBlindValue),
    round(1),
    biggestBet(0),
    numberOfTurn(0)
{}

void PokerGame::startGame() {
    if (dealer >= players.size()) {
        throw new GameException("L'id du dealer est incorrect.");
    }

    if (players.size() < 2 && players.size() >10){
        throw new GameException("Le nombre de joueur est incorrect.");
    }

    deck = Deck();
    deck.fillWith52Cards();

    this->setCurrentPlayerId(dealer);

    this->gameState = GameState::RUNNING;

    // Si le nombre de joueur est égal à 2, le dealer fait office de small blind, il ne faut donc pas passer de tour.
    if (players.size() > 2) {
        this->nextPlayer();
    }

    static_cast<PokerPlayer*>(this->getCurrentPlayer())->bet(this->smallBlindValue);
    this->nextPlayer();
    static_cast<PokerPlayer*>(this->getCurrentPlayer())->bet(this->bigBlindValue);
    this->nextPlayer();
    this->biggestBet = this->bigBlindValue;

    for(unsigned int i=0; i<this->players.size(); ++i) {
        std::cout << static_cast<PokerPlayer*>(this->players[i])->getNickname() << " : " << static_cast<PokerPlayer*>(this->players[i])->getCurrentBet() << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
}

void PokerGame::bet(unsigned int amount=0) {
    if (this->gameState != GameState::RUNNING) {
        throw new GameException("Erreur lors de la mise: la partie n'est pas en cours");
    }

    if (round >= 1 && round <= 2) {
        if (amount != this->bigBlindValue) {
            if ((static_cast<PokerPlayer*>(this->getCurrentPlayer())->getCurrentBet() + amount) != this->biggestBet) {
                throw new GameException("Erreur lors de la mise: la valeur n'est pas égale à la big blind ou ne permet pas d'aligner les mises.");
            }
        }
    } else if (round >= 3 && round <= 4) {
        if (amount != (2*this->bigBlindValue)) {
            throw new GameException("Erreur lors de la mise: la valeur n'est pas égale au double du big blind");
        }
    }
    static_cast<PokerPlayer*>(this->getCurrentPlayer())->bet(amount);
    this->biggestBet = static_cast<PokerPlayer*>(this->getCurrentPlayer())->getCurrentBet();

    this->nextPlayer();
}

void PokerGame::check() {
    if (this->gameState != GameState::RUNNING) {
        throw new GameException("Erreur lors du check : la partie n'est pas en cours");
    }

    for(unsigned int i=0; i<this->players.size(); ++i) {
        if (static_cast<PokerPlayer*>(this->players[i])->getCurrentBet() != 0) {
            throw new GameException("Erreur lors du check : des joueurs ont déjà misés.");
        }
    }

    this->nextPlayer();
}

void PokerGame::fold() {
    if (this->gameState != GameState::RUNNING) {
        throw new GameException("Erreur lors du couchage : la partie n'est pas en cours");
    }

    static_cast<PokerPlayer*>(this->getCurrentPlayer())->fold();
    this->centralBet += static_cast<PokerPlayer*>(this->getCurrentPlayer())->getCurrentBet();
    static_cast<PokerPlayer*>(this->getCurrentPlayer())->resetCurrentBet();

    this->nextPlayer();
}

unsigned int PokerGame::getRound() {
    return this->round;
}

void PokerGame::nextPlayer() {
    if (this->gameState != GameState::RUNNING) {
        throw new GameException("Erreur lors du passage au joueur suivant : la partie n'est pas en cours");
    }

    ++this->numberOfTurn;

    if (this->isRoundOver()) {
        if (round <= 4) {
            for(unsigned int i=0; i<this->players.size(); ++i) {
                this->centralBet += static_cast<PokerPlayer*>(this->players[i])->getCurrentBet();
                static_cast<PokerPlayer*>(this->players[i])->resetCurrentBet();
            }
            this->setCurrentPlayerId(dealer);
            if (players.size() > 2) {
                this->getNextPlayerId();
            }
        } else if (round == 5) {

        }
        ++this->round;
        this->numberOfTurn = 0;
    }

    this->currentPlayer = this->getNextPlayerId();

    for(unsigned int i=0; i<this->players.size(); ++i) {
        std::cout << static_cast<PokerPlayer*>(this->players[i])->getNickname() << " : " << static_cast<PokerPlayer*>(this->players[i])->getCurrentBet() << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
    std::cout << "Round : " << this->round << std::endl;
    std::cout << "Central bet : " << this->centralBet << std::endl;
    std::cout << "------------------------------" << std::endl;
}

unsigned int PokerGame::getNextPlayerId() {
    bool nextPlayerFound = false;
    unsigned int nextPlayer = this->currentPlayer;
    do {
        ++nextPlayer;
        nextPlayer %= players.size();
        if (!((static_cast<PokerPlayer*>(this->players[nextPlayer]))->isFold())) {
            nextPlayerFound = true;
            if (nextPlayer == this->currentPlayer) {
                this->gameState = GameState::OVER;
            }
        }
    } while(!nextPlayerFound);

    return nextPlayer;
}

bool PokerGame::isRoundOver() {
    if (this->gameState != GameState::RUNNING) {
        throw new GameException("Erreur lors de la méthode isRoundOver(): la partie n'est pas en cours");
    }
    bool finish;
    if (this->numberOfTurn >= this->players.size()) {
        finish = true;
        unsigned int i = 1;
        while (finish && i < this->players.size()) {
            finish = (static_cast<PokerPlayer*>(this->players[i-1])->getCurrentBet() == static_cast<PokerPlayer*>(this->players[i])->getCurrentBet());
            ++i;
        }
    } else {
        finish = false;
    }
    return finish;
}
