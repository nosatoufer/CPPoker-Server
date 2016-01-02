#include "roommanager.h"

RoomManager::RoomManager(QString name) :
    m_name(name)
{
    m_mController = new ModelController();
}

RoomManager::~RoomManager()
{
    for(ConnectionManager * player : m_players)
        delete player;
    delete m_mController;
}

void RoomManager::run()
{
    //m_mController.startGame();
}

void RoomManager::readRequest(std::string pName, Request *req)
{
    switch(req->getCommand())
    {
    case POKER_ALL_IN:
        //m_mController->allIN(pName);
        break;
    case POKER_CALL:
        //m_mController->call(pName);
        break;
    case POKER_CHECK:
        //m_mController->check(pName);
        break;
    case POKER_FOLD:
        //m_mController->fold(pName);
        break;
    }
}

void RoomManager::addPlayer(ConnectionManager *player)
{
    // IF GAME != STARTED
    m_players.append(player);
    player->addObserver(this);
}

bool RoomManager::remPlayer(ConnectionManager *player)
{
    return m_players.removeOne(player);
}

QString RoomManager::name() const
{
    return m_name;
}

int RoomManager::nbPlayer() const
{
    return m_players.size();
}

bool RoomManager::checkName(std::string pName) const
{
    int i = 0;
    while( i < m_players.size() && m_players.at(i++)->getNickname() != pName );
    return i < m_players.size();
}

QVector<std::string> RoomManager::playerName() const
{
    QVector<std::string> playersName;
    for(auto p : m_players)
        playersName.append(p->getNickname());
    return playersName;
}

void RoomManager::update()
{

}

void RoomManager::netUpdate()
{
    for(ConnectionManager * player : m_players)
    {
        if(player->hasRequests())
        {
            readRequest(player->getNickname(), player->getRequest());
        }
    }

}


