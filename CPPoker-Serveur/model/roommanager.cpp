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

void RoomManager::readRequest(ConnectionManager *player, Request *req)
{
    switch(req->getCommand())
    {
    case POKER_ALL_IN:
        if (m_mController->allIn(player->getNickname()))
            req->setStatus("STATUS_SUCCESS");
        else
            req->setStatus("STATUS_FAILLURE");
        break;
    case POKER_CALL:
        if (m_mController->call(player->getNickname()))
            req->setStatus("STATUS_SUCCESS");
        else
            req->setStatus("STATUS_FAILLURE");
        break;
    case POKER_CHECK:
        if ( m_mController->check(player->getNickname()))
            req->setStatus("STATUS_SUCCESS");
        else
            req->setStatus("STATUS_FAILLURE");
        break;
    case POKER_FOLD:
        if (m_mController->fold(player->getNickname()))
            req->setStatus("STATUS_SUCCESS");
        else
            req->setStatus("STATUS_FAILLURE");
        break;
    case DISCONNECT:
        remPlayer(player);
        break;
    default:
        req->setStatus("STATUS_FAILLURE");

    }
    if (req->getStatus() == "STATUS_SUCCESS")
    {
        sendToAll(req);
    }
    else
    {
        player->write(req);
        delete req;
    }
}

void RoomManager::sendToAll(Request *req)
{
    for(ConnectionManager* p : m_players)
        p->write(req);
    delete req;
}

void RoomManager::addPlayer(ConnectionManager *player)
{
    // IF m_mController.status() != STARTED

    Request * req = new Request();
    req->setCommand(PLAYER_JOINED);
    req->setMessage(player->getNickname());
    sendToAll(req);
    m_players.append(player);
    player->addObserver(this);
    m_mController->addPlayer(player->getNickname());
    req = new Request();
    req->setCommand(PLAYER_JOINED);
    for(ConnectionManager * p : m_players)
    {
        req->setMessage(p->getNickname());
        player->write(req);
    }
    delete req;

}

bool RoomManager::remPlayer(ConnectionManager *player)
{
    if (m_players.removeOne(player))
    {
        Request * req = new Request();
        req->setCommand(PLAYER_LEFT);
        req->setMessage(player->getNickname());
        sendToAll(req);
        delete player;
    }

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
            readRequest(player, player->getRequest());
        }
    }

}



