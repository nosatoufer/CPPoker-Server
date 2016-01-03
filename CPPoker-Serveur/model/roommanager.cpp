#include "roommanager.h"

RoomManager::RoomManager(QString name, unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind) :
    m_name(name),
    m_players()
{
    m_mController = new PokerController(minPlayer, maxPlayer, smallBlind, bigBlind);
}

RoomManager::~RoomManager()
{
    for(ConnectionManager * player : m_players)
        delete player;
    delete m_mController;
}

void RoomManager::run()
{
    while(true)
    {
        for(ConnectionManager* user : m_players)
        {
            //qDebug() << "Analyzing client requests";
            if (user->hasRequests())
            {
                // qDebug() << "Has request";
                this->manageRequest(user);
            } else {
                // qDebug() << "No request";
            }
        }
        if (this->m_mController->readyToStart()) {
            this->m_mController->startGame();
        }
    }
    //m_mController.startGame();
}

void RoomManager::manageRequest(ConnectionManager *player)
{
    Request* req = player->getRequest();
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
    int i = m_players.indexOf(player);
    if (i != -1)
    {
        if (m_mController->isPlayerInGame(player->getNickname())) {
            m_mController->cancelGame();
        }
        m_players.remove(i);
        Request * req = new Request();
        req->setCommand(PLAYER_LEFT);
        req->setMessage(player->getNickname());
        sendToAll(req);
        delete player;
        return true;
    }
    return false;
}

QString RoomManager::name() const
{
    return m_name;
}

int RoomManager::nbPlayer() const
{
    return m_players.size();
}

bool RoomManager::isNicknameAvailable(std::string pName) const
{
    int i = 0;
    bool find = false;
    while(!find && i < m_players.size()) {
        find = (m_players[i]->getNickname() == pName);
        ++i;
    }
    return !find;
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
            //readRequest(player, player->getRequest());
        }
    }

}

std::string RoomManager::toString()
{
    std::map<std::string, std::string> map;
    map["name"] = this->m_name.toStdString();
    map["minPlayer"] = std::to_string(this->m_mController->getMinPlayer());
    map["maxPlayer"] = std::to_string(this->m_mController->getMaxPlayer());
    map["smallBlind"] = std::to_string(this->m_mController->getSmallBlind());
    map["bigBlind"] = std::to_string(this->m_mController->getBigBlind());
    map["currentPlayer"] = std::to_string(this->m_players.size());
    return jsonEncode(map);
}


