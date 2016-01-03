#include "pokergame.h"

PokerGame::PokerGame(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlindValue, unsigned int bigBlindValue, std::vector<PokerPlayer*> players, unsigned int dealer) :
    m_players(players),
    m_tableCard(std::vector<Card*>()),
    m_deck(),
    m_gameState(GameState::WAITING),
    m_currentPlayer(0),
    m_minPlayer(minPlayer),
    m_maxPlayer(maxPlayer),
    m_dealer(dealer),
    m_smallBlindValue(smallBlindValue),
    m_bigBlindValue(bigBlindValue),
    m_round(1),
    m_biggestBet(0),
    m_numberOfTurn(0),
    m_pot(0)
{}

PokerGame::~PokerGame() {
    for (PokerPlayer* player : this->m_players) {
        delete player;
    }
}

void PokerGame::addPlayer(PokerPlayer* player) {
    this->m_players.push_back(player);
}

void PokerGame::setCurrentPlayerId(unsigned int number) {
    if (number >= this->m_players.size()) {
        throw GameException("Le numéro de joueur est supérieur au nombre de joueur.");
    }
    this->m_currentPlayer = number;
}

bool PokerGame::readyToStart() {
    if (this->m_gameState != GameState::RUNNING) {
        return (this->m_players.size() <= m_maxPlayer && this-> m_players.size() >= m_minPlayer);
    } else {
        return false;
    }
}

PokerPlayer* PokerGame::getPlayer(std::string nickname) {
    for (PokerPlayer* player : this->m_players) {
        if (player->getNickname() == nickname)
            return player;
    }
    throw new GameException("Erreur lors de l'appel à getPlayer : le joueur n'est pas dans la partie.");
}

std::string PokerGame::getCurrentPlayerNickname() {
    return this->getCurrentPlayer()->getNickname();
}

PokerPlayer* PokerGame::getCurrentPlayer() {
    return this->m_players[this->m_currentPlayer];
}

std::vector<PokerPlayer*> PokerGame::getPlayers() {
    return this->m_players;
}

unsigned int PokerGame::getCurrentPlayerId() {
    return this->m_currentPlayer;
}

GameState PokerGame::getGameState() {
    return this->m_gameState;
}

void PokerGame::cancelGame() {
    this->m_gameState = GameState::OVER;
}


void PokerGame::startGame() {
    if (m_dealer >= this->m_players.size()) {
        throw GameException("L'id du dealer est incorrect.");
    }

    if (this->m_players.size() < 2 && this->m_players.size() >10) {
        throw GameException("Le nombre de joueur est incorrect.");
    }

    m_deck.fillWith52Cards();

    // Distribution des deux cartes à chaque joueur
    for(unsigned int i=0; i<(this->m_players.size()*2); ++i) {
        this->m_players[i%this->m_players.size()]->addCard(m_deck.randomPick());
    }


    this->m_gameState = GameState::RUNNING;

    this->setCurrentPlayerId(m_dealer);
    // Si le nombre de joueur est égal à 2, le dealer fait office de small blind, il ne faut donc pas passer au joueur suivant
    if (this->m_players.size() > 2) {
        this->nextPlayer();
    }

    // Mise obligatoire de la small blind et big blind (il faudra donc vérifier que chaque joueur rejoignant une room a au
    // moins la somme de la big blind en cash).
    this->getCurrentPlayer()->bet(this->m_smallBlindValue);
    this->nextPlayer();
    this->getCurrentPlayer()->bet(this->m_bigBlindValue);
    this->nextPlayer();
    this->m_biggestBet = this->m_bigBlindValue;
}

void PokerGame::bet(unsigned int amount=0) {
    if (this->m_gameState != GameState::RUNNING) {
        throw GameException("Erreur lors de la mise: la partie n'est pas en cours");
    }

    if (m_round >= 1) {
        // Dans le round 1, la première mise doit être de la valeur de la small blind
        if (this->m_numberOfTurn == 0) {
            if (amount != this->m_smallBlindValue) {
                throw GameException("Erreur lors de la mise: la valeur n'est pas égale à la small blind.");
            }
        } else {
            // Ensuite, la mise de relance doit être égale à la big blind value.
            if (amount != this->m_bigBlindValue) {
                // La seule exception, est dans le cas ou un joueur doit aligner les mises courantes (exemple : small blind).
                // Dans ce cas, on utilise la valeur de biggestBet pour vérifier si c'est bien correct.
                if ((this->getCurrentPlayer()->getCurrentBet() + amount) != this->m_biggestBet) {
                    throw GameException("Erreur lors de la mise: la valeur n'est pas égale à la big blind ou ne permet pas d'aligner les mises.");
                }
            }
        }
    } else if (m_round <= 2) {
        // Dans le round 2, une mise une relance doit être égale à la big blind value.
        if (amount != this->m_bigBlindValue) {
            // La seule exception, est dans le cas ou un joueur doit aligner les mises courantes (exemple : small blind).
            // Dans ce cas, on utilise la valeur de biggestBet pour vérifier si c'est bien correct.
            if ((this->getCurrentPlayer()->getCurrentBet() + amount) != this->m_biggestBet) {
                throw GameException("Erreur lors de la mise: la valeur n'est pas égale à la big blind ou ne permet pas d'aligner les mises.");
            }
        }
    } else if (m_round >= 3 && m_round <= 4) {
        // Dans le round 3 et 4, la mise ou relance doit être de 2 fois la valeur de la big blind
        if (amount != (2*this->m_bigBlindValue)) {
            throw GameException("Erreur lors de la mise: la valeur n'est pas égale au double du big blind");
        }
    }

    // On modifie la valeur dans le Player
    this->getCurrentPlayer()->bet(amount);

    // On modifie la valeur de biggestBet
    this->m_biggestBet = this->getCurrentPlayer()->getCurrentBet();

    this->nextPlayer();
}

void PokerGame::check() {
    if (this->m_gameState != GameState::RUNNING) {
        throw GameException("Erreur lors du check : la partie n'est pas en cours");
    }

    // Un joueur peut checker (ne pas miser en restant dans la partie) seulement si aucun autre joueur n'a déjà misé
    for(unsigned int i=0; i<this->m_players.size(); ++i) {
        if (this->m_players[i] != 0) {
            throw new GameException("Erreur lors du check : des joueurs ont déjà misés.");
        }
    }

    this->nextPlayer();
}

void PokerGame::allIn() {
    if (this->m_gameState != GameState::RUNNING) {
        throw GameException("Erreur lors du all-in : la partie n'est pas en cours");
    }

    // Un joueur peut partir all-in seulement s'il n'a plus suffisament de cash pour rester en jeu
    unsigned int cash = this->getCurrentPlayer()->getCash();
    if (m_round >= 1 && m_round <= 2) {
        if (cash >= this->m_bigBlindValue) {
            throw new GameException("Erreur lors du all-in : vous avez encore assez de cash pour miser !");
        }
    } else if (m_round >= 3 && m_round <= 4) {
        if (cash >= (2*this->m_bigBlindValue)) {
            throw new GameException("Erreur lors du all-in : vous avez encore assez d'argent pour miser !");
        }
    }

    // Il mise alors tout ce qu'il lui reste :
    this->getCurrentPlayer()->bet(cash);

    if (this->numberOfActivePlayer() == 2) {
        // Si il reste 2 joueurs (avec celui partant en all-in), l'autre joueur s'alignent et la partie se fini en
        // retournant les cartes restantes
        this->m_biggestBet = this->getCurrentPlayer()->getCurrentBet();
        this->getCurrentPlayer()->setAllIn(true);
        this->nextPlayer();
        if (this->getCurrentPlayer()->getCurrentBet() > this->m_biggestBet) {
            this->getCurrentPlayer()->reduceBetTo(this->m_biggestBet);
        }
        this->putBetsInPot();
        switch(this->m_round) {
            case 1:
                for(unsigned int i=0; i<3; ++i) {
                    this->m_tableCard.push_back(m_deck.randomPick());
                }
            case 2:
                this->m_tableCard.push_back(m_deck.randomPick());

            case 3:
                this->m_tableCard.push_back(m_deck.randomPick());
            break;
        }
        this->m_gameState = GameState::OVER;
    } else {
        // S'il reste encore des joueurs, la partie continue normalement. A la fin, le joueur partant en All-in ne pourra gagner
        // que nombre_de_joueurs*sa_mise_maximale, le montant restant sera redivisé entre les autres joueurs
        this->getCurrentPlayer()->setAllIn(true);
        this->nextPlayer();
    }
}

void PokerGame::fold() {
    if (this->m_gameState != GameState::RUNNING) {
        throw GameException("Erreur lors du couchage : la partie n'est pas en cours");
    }

    // Le joueur se couche et perd sa mise en cours
    this->getCurrentPlayer()->setFold(true);
    this->m_pot += static_cast<PokerPlayer*>(this->getCurrentPlayer())->getCurrentBet();
    this->getCurrentPlayer()->resetCurrentBet();
    this->getCurrentPlayer()->resetTotalBet();

    this->nextPlayer();
}

unsigned int PokerGame::getRound() {
    return this->m_round;
}

void PokerGame::nextPlayer() {
    // Méthode pour passer au joueur suivant, elle s'occupe également de la gestion des rounds et des mises des joueurs.

    if (this->m_gameState != GameState::RUNNING) {
        throw GameException("Erreur lors du passage au joueur suivant : la partie n'est pas en cours");
    }

    if ((!this->getCurrentPlayer()->isFold()) && (!this->getCurrentPlayer()->isAllIn())) {
        ++this->m_numberOfTurn;
    }

    if (this->isRoundOver()) {
        // DEBUG : std::cout << "ROUND OVER" << std::endl;
        if (this->m_round < 4) {
            switch (this->m_round) {
                case 1:
                    for(unsigned int i=0; i<3; ++i) {
                        this->m_tableCard.push_back(m_deck.randomPick());
                    }
                break;

                case 2:
                    this->m_tableCard.push_back(m_deck.randomPick());
                break;

                case 3:
                    this->m_tableCard.push_back(m_deck.randomPick());
                break;
            }

            this->putBetsInPot();

            this->setCurrentPlayerId(m_dealer);
            if (this->m_players.size() > 2) {
                this->getNextPlayerId();
            }

            ++this->m_round;
            this->m_numberOfTurn = 0;
        } else if (m_round == 4) {
            this->putBetsInPot();
            ++this->m_round;
            this->m_numberOfTurn = 0;
            this->m_gameState = GameState::OVER;
        }
    } else {
        // DEBUG : std::cout << "ROUND NOT OVER" << std::endl;
    }

    this->m_currentPlayer = this->getNextPlayerId();

    for(unsigned int i=0; i<this->m_players.size(); ++i) {
        std::cout << this->m_players[i]->getNickname() << " : " << this->m_players[i]->getCurrentBet() << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
    std::cout << "Round : " << this->m_round << std::endl;
    std::cout << "Central bet : " << this->m_pot << std::endl;
    std::cout << "------------------------------" << std::endl;
}

unsigned int PokerGame::getNextPlayerId() {
    bool nextPlayerFound = false;
    unsigned int nextPlayerId = this->m_currentPlayer;

    do {
        ++nextPlayerId;
        nextPlayerId %= this->m_players.size();
        if ((!((this->m_players[nextPlayerId])->isFold())) && (!((this->m_players[nextPlayerId])->isAllIn()))) {
            nextPlayerFound = true;
            if (nextPlayerId == this->m_currentPlayer) {
                this->m_gameState = GameState::OVER;
            }
        }
    } while(!nextPlayerFound);

    return nextPlayerId;
}

bool PokerGame::isRoundOver() {
    if (this->m_gameState != GameState::RUNNING) {
        throw GameException("Erreur lors de la méthode isRoundOver(): la partie n'est pas en cours");
    }
    bool finish;
    std::cout << this->m_numberOfTurn << " " << this->numberOfActivePlayer() << std::endl;
    if (this->m_numberOfTurn >= this->numberOfActivePlayer()) {
        finish = true;
        unsigned int i = 1;
        while (finish && i < this->m_players.size()) {
            finish = (this->m_players[i-1]->getCurrentBet() == this->m_players[i]->getCurrentBet());
            ++i;
        }
    } else {
        finish = false;
    }
    return finish;
}

unsigned int PokerGame::numberOfActivePlayer() {
    unsigned int numberOfActiverPlayerLeft = this->m_players.size();
    // DEBUG : std::cout << numberOfActiverPlayerLeft << std::endl;
    for(unsigned int i=0; i<this->m_players.size(); ++i) {
        if (this->m_players[i]->isFold() || this->m_players[i]->isAllIn()) {
            --numberOfActiverPlayerLeft;
            // DEBUG : std::cout << "-1" << std::endl;
        }
    }
    return numberOfActiverPlayerLeft;
}

std::vector<Card*> PokerGame::getTableCard() {
    return this->m_tableCard;
}

void PokerGame::putBetsInPot() {
    // Récupère les mises de tous les joueurs et les place dans le pot.
    for(unsigned int i=0; i<this->m_players.size(); ++i) {
        this->m_pot += this->m_players[i]->getCurrentBet();
        this->m_players[i]->resetCurrentBet();
    }
}

unsigned int PokerGame::getMinPlayer()
{
    return this->m_minPlayer;
}

unsigned int PokerGame::getMaxPlayer()
{
    return this->m_maxPlayer;
}

unsigned int PokerGame::getSmallBlind() {
    return this->m_smallBlindValue;
}

unsigned int PokerGame::getBigBlind() {
    return this->m_bigBlindValue;
}
