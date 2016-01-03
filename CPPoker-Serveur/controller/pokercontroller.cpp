#include "pokercontroller.h"

PokerController::PokerController(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind)
{
    model = new PokerRoom(minPlayer, maxPlayer, smallBlind, bigBlind);
    //model->attachController(this);
}

PokerController::~PokerController()
{
    delete model;
}

PokerController::PokerController(PokerRoom* room) :
    model(room)
{
    //model->attachController(this);
}

bool PokerController::allIn(std::string name)
{

}

bool PokerController::call(std::string name)
{

}

bool PokerController::check(std::string name)
{

}

bool PokerController::raise(std::string name)
{

}

bool PokerController::fold(std::string name)
{

}

bool PokerController::isPlayerInGame(std::string nickname)
{
    std::vector<Player*> players = this->model->getGame()->getPlayers();
    for (Player* player : players) {
        if (player->getNickname() == nickname)
            return true;
    }
    return false;
}

void PokerController::cancelGame()
{
    this->model->cancelGame();
}

bool PokerController::addPlayer(std::string name)
{
    this->model->addPlayer(new PokerPlayer(name, 1000));
}

bool PokerController::readyToStart()
{
    return this->model->readyToStart();
}

void PokerController::startGame()
{
    this->model->startGame();
}

unsigned int PokerController::getMinPlayer()
{
    return this->model->getMinPlayer();
}

unsigned int PokerController::getMaxPlayer()
{
    return this->model->getMaxPlayer();
}

unsigned int PokerController::getSmallBlind()
{
    return this->model->getSmallBlind();
}

unsigned int PokerController::getBigBlind()
{
    return this->model->getBigBlind();
}

void PokerController::update()
{
    //
}
