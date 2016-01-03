#include "pokergame.h"

PokerGame::PokerGame(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlindValue, unsigned int bigBlindValue, std::vector<PokerPlayer*> players, unsigned int dealer) :
    tableCard(std::vector<Card*>()),
    players(players),
    gameState(GameState::WAITING),
    currentPlayer(0),
    minPlayer(minPlayer),
    maxPlayer(maxPlayer),
    dealer(dealer),
    smallBlindValue(smallBlindValue),
    bigBlindValue(bigBlindValue),
    round(1),
    biggestBet(0),
    numberOfTurn(0),
    pot(0)
{}

void PokerGame::addPlayer(PokerPlayer* player) {
    this->players.push_back(player);
}

void PokerGame::setCurrentPlayerId(unsigned int number) {
    if (number >= players.size()) {
        throw GameException("Le numéro de joueur est supérieur au nombre de joueur.");
    }
    this->currentPlayer = number;
}

bool PokerGame::readyToStart() {
    if (this->gameState != GameState::RUNNING) {
        return (this->players.size() <= maxPlayer && this-> players.size() >= minPlayer);
    } else {
        return false;
    }
}

PokerPlayer* PokerGame::getPlayer(std::string nickname) {
    for (PokerPlayer* player : players) {
        if (player->getNickname() == nickname)
            return player;
    }
    throw new GameException("Erreur lors de l'appel à getPlayer : le joueur n'est pas dans la partie.");
}

std::string PokerGame::getCurrentPlayerNickname() {
    return this->getCurrentPlayer()->getNickname();
}

PokerPlayer* PokerGame::getCurrentPlayer() {
    return this->players[this->currentPlayer];
}

std::vector<PokerPlayer*> PokerGame::getPlayers() {
    return this->players;
}

unsigned int PokerGame::getCurrentPlayerId() {
    return this->currentPlayer;
}

GameState PokerGame::getGameState() {
    return this->gameState;
}

void PokerGame::cancelGame() {
    this->gameState = GameState::OVER;
}


void PokerGame::startGame() {
    if (dealer >= players.size()) {
        throw GameException("L'id du dealer est incorrect.");
    }

    if (players.size() < 2 && players.size() >10) {
        throw GameException("Le nombre de joueur est incorrect.");
    }

    deck = Deck();
    deck.fillWith52Cards();

    // Distribution des deux cartes à chaque joueur
    for(unsigned int i=0; i<(this->players.size()*2); ++i) {
        this->players[i%this->players.size()]->addCard(deck.randomPick());
    }


    this->gameState = GameState::RUNNING;

    this->setCurrentPlayerId(dealer);
    // Si le nombre de joueur est égal à 2, le dealer fait office de small blind, il ne faut donc pas passer au joueur suivant
    if (players.size() > 2) {
        this->nextPlayer();
    }

    // Mise obligatoire de la small blind et big blind (il faudra donc vérifier que chaque joueur rejoignant une room a au
    // moins la somme de la big blind en cash).
    this->getCurrentPlayer()->bet(this->smallBlindValue);
    this->nextPlayer();
    this->getCurrentPlayer()->bet(this->bigBlindValue);
    this->nextPlayer();
    this->biggestBet = this->bigBlindValue;
}

void PokerGame::bet(unsigned int amount=0) {
    if (this->gameState != GameState::RUNNING) {
        throw GameException("Erreur lors de la mise: la partie n'est pas en cours");
    }

    if (round >= 1 && round <= 2) {
        // Dans le round 1 et 2, une mise une relance doit être égale à la big blind value.
        if (amount != this->bigBlindValue) {
            // La seule exception, est dans le cas ou un joueur doit aligner les mises courantes (exemple : small blind).
            // Dans ce cas, on utilise la valeur de biggestBet pour vérifier si c'est bien correct.
            if ((this->getCurrentPlayer()->getCurrentBet() + amount) != this->biggestBet) {
                throw new GameException("Erreur lors de la mise: la valeur n'est pas égale à la big blind ou ne permet pas d'aligner les mises.");
            }
        }
    } else if (round >= 3 && round <= 4) {
        // Dans le round 3 et 4, la mise ou relance doit être de 2 fois la valeur de la big blind
        if (amount != (2*this->bigBlindValue)) {
            throw new GameException("Erreur lors de la mise: la valeur n'est pas égale au double du big blind");
        }
    }

    // On modifie la valeur dans le Player
    this->getCurrentPlayer()->bet(amount);

    // On modifie la valeur de biggestBet
    this->biggestBet = this->getCurrentPlayer()->getCurrentBet();

    this->nextPlayer();
}

void PokerGame::check() {
    if (this->gameState != GameState::RUNNING) {
        throw GameException("Erreur lors du check : la partie n'est pas en cours");
    }

    // Un joueur peut checker (ne pas miser en restant dans la partie) seulement si aucun autre joueur n'a déjà misé
    for(unsigned int i=0; i<this->players.size(); ++i) {
        if (this->players[i] != 0) {
            throw new GameException("Erreur lors du check : des joueurs ont déjà misés.");
        }
    }

    this->nextPlayer();
}

void PokerGame::allIn() {
    if (this->gameState != GameState::RUNNING) {
        throw GameException("Erreur lors du all-in : la partie n'est pas en cours");
    }

    // Un joueur peut partir all-in seulement s'il n'a plus suffisament de cash pour rester en jeu
    unsigned int cash = this->getCurrentPlayer()->getCash();
    if (round >= 1 && round <= 2) {
        if (cash >= this->bigBlindValue) {
            throw new GameException("Erreur lors du all-in : vous avez encore assez de cash pour miser !");
        }
    } else if (round >= 3 && round <= 4) {
        if (cash >= (2*this->bigBlindValue)) {
            throw new GameException("Erreur lors du all-in : vous avez encore assez d'argent pour miser !");
        }
    }

    // Il mise alors tout ce qu'il lui reste :
    this->getCurrentPlayer()->bet(cash);

    if (this->numberOfActivePlayer() == 2) {
        // Si il reste 2 joueurs (avec celui partant en all-in), l'autre joueur s'alignent et la partie se fini en
        // retournant les cartes restantes
        this->biggestBet = this->getCurrentPlayer()->getCurrentBet();
        this->getCurrentPlayer()->setAllIn(true);
        this->nextPlayer();
        if (this->getCurrentPlayer()->getCurrentBet() > this->biggestBet) {
            this->getCurrentPlayer()->reduceBetTo(this->biggestBet);
        }
        this->putBetsInPot();
        switch(this->round) {
            case 1:
                for(unsigned int i=0; i<3; ++i) {
                    this->tableCard.push_back(deck.randomPick());
                }
            case 2:
                this->tableCard.push_back(deck.randomPick());

            case 3:
                this->tableCard.push_back(deck.randomPick());
            break;
        }
        this->gameState = GameState::OVER;
    } else {
        // S'il reste encore des joueurs, la partie continue normalement. A la fin, le joueur partant en All-in ne pourra gagner
        // que nombre_de_joueurs*sa_mise_maximale, le montant restant sera redivisé entre les autres joueurs
        this->getCurrentPlayer()->setAllIn(true);
        this->nextPlayer();
    }
}

void PokerGame::fold() {
    if (this->gameState != GameState::RUNNING) {
        throw GameException("Erreur lors du couchage : la partie n'est pas en cours");
    }

    // Le joueur se couche et perd sa mise en cours
    this->getCurrentPlayer()->setFold(true);
    this->pot += static_cast<PokerPlayer*>(this->getCurrentPlayer())->getCurrentBet();
    this->getCurrentPlayer()->resetCurrentBet();
    this->getCurrentPlayer()->resetTotalBet();

    this->nextPlayer();
}

unsigned int PokerGame::getRound() {
    return this->round;
}

void PokerGame::nextPlayer() {
    // Méthode pour passer au joueur suivant, elle s'occupe également de la gestion des rounds et des mises des joueurs.

    if (this->gameState != GameState::RUNNING) {
        throw GameException("Erreur lors du passage au joueur suivant : la partie n'est pas en cours");
    }

    if ((!this->getCurrentPlayer()->isFold()) && (!this->getCurrentPlayer()->isAllIn())) {
        ++this->numberOfTurn;
    }

    if (this->isRoundOver()) {
        // DEBUG : std::cout << "ROUND OVER" << std::endl;
        if (this->round < 4) {
            switch (this->round) {
                case 1:
                    for(unsigned int i=0; i<3; ++i) {
                        this->tableCard.push_back(deck.randomPick());
                    }
                break;

                case 2:
                    this->tableCard.push_back(deck.randomPick());
                break;

                case 3:
                    this->tableCard.push_back(deck.randomPick());
                break;
            }

            this->putBetsInPot();

            this->setCurrentPlayerId(dealer);
            if (players.size() > 2) {
                this->getNextPlayerId();
            }

            ++this->round;
            this->numberOfTurn = 0;
        } else if (round == 4) {
            this->putBetsInPot();
            ++this->round;
            this->numberOfTurn = 0;
            this->gameState = GameState::OVER;
        }
    } else {
        // DEBUG : std::cout << "ROUND NOT OVER" << std::endl;
    }

    this->currentPlayer = this->getNextPlayerId();

    for(unsigned int i=0; i<this->players.size(); ++i) {
        std::cout << this->players[i]->getNickname() << " : " << this->players[i]->getCurrentBet() << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
    std::cout << "Round : " << this->round << std::endl;
    std::cout << "Central bet : " << this->pot << std::endl;
    std::cout << "------------------------------" << std::endl;
}

unsigned int PokerGame::getNextPlayerId() {
    bool nextPlayerFound = false;
    unsigned int nextPlayerId = this->currentPlayer;

    do {
        ++nextPlayerId;
        nextPlayerId %= players.size();
        if ((!((this->players[nextPlayerId])->isFold())) && (!((this->players[nextPlayerId])->isAllIn()))) {
            nextPlayerFound = true;
            if (nextPlayerId == this->currentPlayer) {
                this->gameState = GameState::OVER;
            }
        }
    } while(!nextPlayerFound);

    return nextPlayerId;
}

bool PokerGame::isRoundOver() {
    if (this->gameState != GameState::RUNNING) {
        throw GameException("Erreur lors de la méthode isRoundOver(): la partie n'est pas en cours");
    }
    bool finish;
    std::cout << this->numberOfTurn << " " << this->numberOfActivePlayer() << std::endl;
    if (this->numberOfTurn >= this->numberOfActivePlayer()) {
        finish = true;
        unsigned int i = 1;
        while (finish && i < this->players.size()) {
            finish = (this->players[i-1]->getCurrentBet() == this->players[i]->getCurrentBet());
            ++i;
        }
    } else {
        finish = false;
    }
    return finish;
}

unsigned int PokerGame::numberOfActivePlayer() {
    unsigned int numberOfActiverPlayerLeft = this->players.size();
    // DEBUG : std::cout << numberOfActiverPlayerLeft << std::endl;
    for(unsigned int i=0; i<this->players.size(); ++i) {
        if (this->players[i]->isFold() || this->players[i]->isAllIn()) {
            --numberOfActiverPlayerLeft;
            // DEBUG : std::cout << "-1" << std::endl;
        }
    }
    return numberOfActiverPlayerLeft;
}

std::vector<Card*> PokerGame::getTableCard() {
    return this->tableCard;
}

void PokerGame::putBetsInPot() {
    // Récupère les mises de tous les joueurs et les place dans le pot.
    for(unsigned int i=0; i<this->players.size(); ++i) {
        this->pot += this->players[i]->getCurrentBet();
        this->players[i]->resetCurrentBet();
    }
}

unsigned int PokerGame::getMinPlayer()
{
    return this->minPlayer;
}

unsigned int PokerGame::getMaxPlayer()
{
    return this->maxPlayer;
}

unsigned int PokerGame::getSmallBlind() {
    return this->smallBlindValue;
}

unsigned int PokerGame::getBigBlind() {
    return this->bigBlindValue;
}
