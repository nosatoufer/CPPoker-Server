#include "pokercontroller.h"

PokerController::PokerController(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind)
{
    m_game = new PokerGame(minPlayer, maxPlayer, smallBlind, bigBlind);
}

PokerController::~PokerController()
{
    delete m_game;
}

bool PokerController::allIn(std::string name)
{
    bool val = (m_game->getCurrentPlayerNickname() == name);
    if (val)
        m_game->allIn();

    return val;
}

bool PokerController::bet(std::string name, unsigned int value)
{
    bool val = (m_game->getCurrentPlayerNickname() == name);
    if (val)
        m_game->bet(value);

    return val;
}

bool PokerController::fold(std::string name)
{
    bool val = (m_game->getCurrentPlayerNickname() == name);
    if (val)
        m_game->fold();

    return val;
}

bool PokerController::check(std::string name)
{
    bool val = (m_game->getCurrentPlayerNickname() == name);
    if (val)
    {}

    return val;
}

bool PokerController::isGameStarted() {
    return (this->m_game->getGameState() == GameState::RUNNING);
}

std::pair<std::string, std::string> PokerController::getPlayerCards(std::string nickname) {
    std::vector<Card*> cards = this->m_game->getPlayer(nickname)->getHand();
    std::pair<std::string, std::string> playerHand;
    playerHand.first = cards[0]->toString();
    playerHand.second = cards[1]->toString();
    return playerHand;
}

void PokerController::cancelGame()
{
    this->m_game->cancelGame();
}

bool PokerController::addPlayer(std::string name)
{
    this->m_game->addPlayer(new PokerPlayer(name, 1000));
    return true;
}

bool PokerController::readyToStart()
{
    return this->m_game->readyToStart();
}

void PokerController::startGame()
{
    this->m_game->startGame();
}

unsigned int PokerController::getMinPlayer()
{
    return this->m_game->getMinPlayer();
}

unsigned int PokerController::getMaxPlayer()
{
    return this->m_game->getMaxPlayer();
}

unsigned int PokerController::getSmallBlind()
{
    return this->m_game->getSmallBlind();
}

unsigned int PokerController::getBigBlind()
{
    return this->m_game->getBigBlind();
}

std::string PokerController::getCurrentPlayerNickname()
{
    return this->m_game->getCurrentPlayerNickname();
}

