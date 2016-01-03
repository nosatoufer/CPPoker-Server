#include "pokercontroller.h"

PokerController::PokerController(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind)
{
    game = new PokerGame(minPlayer, maxPlayer, smallBlind, bigBlind);
    this->game->addObserver(this);
}

PokerController::~PokerController()
{
    delete game;
}

bool PokerController::allIn(std::string name)
{
    bool val = (game->getCurrentPlayerNickname() == name);
    if (val)
        game->allIn();

    return val;
}

bool PokerController::bet(std::string name, unsigned int value)
{
    bool val = (game->getCurrentPlayerNickname() == name);
    if (val)
        game->bet(value);

    return val;
}

bool PokerController::fold(std::string name)
{
    bool val = (game->getCurrentPlayerNickname() == name);
    if (val)
        game->fold();

    return val;
}

bool PokerController::check(std::string name)
{
    bool val = (game->getCurrentPlayerNickname() == name);
    if (val)
    {}

    return val;
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

std::string PokerController::getCurrentPlayerNickname()
{
    return this->game->getCurrentPlayerNickname();
}

void PokerController::update()
{

}
