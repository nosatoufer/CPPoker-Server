#include "pokercontroller.h"

PokerController::PokerController(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind)
{
    game = new PokerGame(minPlayer, maxPlayer, smallBlind, bigBlind);
}

PokerController::~PokerController()
{
    delete game;
}

bool PokerController::allIn(std::string name)
{
    if (game->getCurrentPlayerNickname() == name)
        game->allIn();

    return (game->getCurrentPlayerNickname() == name);
}

bool PokerController::bet(std::string name, unsigned int value)
{
    if (game->getCurrentPlayerNickname() == name)
        game->bet(value);

    return (game->getCurrentPlayerNickname() == name);
}

bool PokerController::fold(std::string name)
{
    if (game->getCurrentPlayerNickname() == name)
        game->fold();

    return (game->getCurrentPlayerNickname() == name);
}

bool PokerController::isGameStarted() {
    return (this->game->getGameState() == GameState::RUNNING);
}

std::pair<std::string, std::string> PokerController::getPlayerCards(std::string nickname) {
    std::vector<Card*> cards = this->game->getPlayer(nickname)->getHand();
    std::pair<std::string, std::string> playerHand;
    playerHand.first = cards[0]->toString();
    playerHand.second = cards[1]->toString();
    return playerHand;
}

void PokerController::cancelGame()
{
    this->game->cancelGame();
}

bool PokerController::addPlayer(std::string name)
{
    this->game->addPlayer(new PokerPlayer(name, 1000));
    return true;
}

bool PokerController::readyToStart()
{
    return this->game->readyToStart();
}

void PokerController::startGame()
{
    this->game->startGame();
}

unsigned int PokerController::getMinPlayer()
{
    return this->game->getMinPlayer();
}

unsigned int PokerController::getMaxPlayer()
{
    return this->game->getMaxPlayer();
}

unsigned int PokerController::getSmallBlind()
{
    return this->game->getSmallBlind();
}

unsigned int PokerController::getBigBlind()
{
    return this->game->getBigBlind();
}

void PokerController::update()
{
    //
}
