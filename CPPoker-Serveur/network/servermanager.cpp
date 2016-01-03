#include "servermanager.h"
#include <QDebug>

ServerManager::ServerManager(ServerController* servController) :
    m_users(),
    m_rooms(),
    m_servController(servController),
    m_disc(nullptr)
{
    m_servController->addLog("Démarrage du ServerManager");
}

ServerManager::~ServerManager()
{
    for(PokerManager * room : m_rooms)
        delete room;
    for(ConnectionManager * user : m_users)
        delete user;
    if(m_disc != nullptr)
        delete m_disc;
}

void ServerManager::addUser(ConnectionManager *user)
{
    m_servController->addLog("User has joined the server");

    m_users.append(user);
}

void ServerManager::manageRequest(ConnectionManager *user) throw()
{
    qDebug() << "Managing request";
    Request* req = user->getRequest();
    switch(req->getCommand())
    {
    case LOGIN:
        m_servController->addLog("Login request : " + req->get("pName"));
        if (isNicknameAvailable(req->get("pName")))
        {
            user->setNickName(req->get("pName"));
            req->setStatus(Request::STATUS_SUCCESS);
            user->write(req);
        }
        else
        {
            req->setStatus(Request::STATUS_FAILURE);
            user->write(req);
        }
        break;
    case ROOM_LIST:
        this->sendRoomList(user, req);
        break;

    case ROOM_CREATE:
        if(createRoom(req->get("name"),
                      std::stoul(req->get("minPlayer")),
                      std::stoul(req->get("maxPlayer")),
                      std::stoul(req->get("smallBlind")),
                      std::stoul(req->get("bigBlind"))))
        {
            this->sendRoomList(user, req);
        } else {
            req->setStatus(Request::STATUS_FAILURE);
            user->write(req);
        }
        break;

    case ROOM_JOIN:
        if(joinRoom(user, req->get("rName"))) {
            req->setStatus(Request::STATUS_SUCCESS);
        } else {
            req->setStatus(Request::STATUS_FAILURE);
        }
        user->write(req);
        break;

    default:
        req->setStatus(Request::STATUS_FAILURE);
        req->setMessage("Requête non valide.");
        user->write(req);
    }
    delete req;
    qDebug() << "Ending managing request";
}

std::map<std::string, std::string> ServerManager::roomList() {
    std::map<std::string, std::string> map;
    unsigned int i=0;
    for(PokerManager * room : m_rooms)
    {
        map["room"+std::to_string(i)] = room->toString();
        ++i;
    }
    return map;
}

bool ServerManager::createRoom(std::string name, unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind)
{
    if (checkRoomName(name))
        return false;
    PokerManager* rm = new PokerManager(QString::fromStdString(name), minPlayer, maxPlayer, smallBlind, bigBlind);
    m_rooms.append(rm);
    return true;
}

bool ServerManager::checkRoomName(std::string name)
{
    int i = 0;
    while( i < m_rooms.size() && m_rooms.at(i++)->name().toStdString() != name);
    return i < m_rooms.size();
}

bool ServerManager::joinRoom(ConnectionManager *user, std::string name)
{
    int i = 0;
    while( i < m_rooms.size() && m_rooms.at(i)->name().toStdString() != name);
    if(i < m_rooms.size())
    {
        m_rooms.at(i)->addPlayer(user);
        int i = m_users.indexOf(user);
        m_users.remove(i);
        return true;
    }
    return false;
}

bool ServerManager::isNicknameAvailable(std::string name)
{
    int i = 0;
    bool find = false;
    while( !find && i < m_users.size() )
    {
        find = (m_users.at(i)->getNickname() == name);
        ++i;
    }
    i = 0;
    while( !find && i < m_rooms.size() )
    {
        find = !m_rooms.at(i)->isNicknameAvailable(name);
        ++i;
    }
    return !find;
}

void ServerManager::sendRoomList(ConnectionManager* user, Request *req)
{
    req->setCommand(ROOM_LIST);
    req->setMap("rooms", this->roomList());
    req->setStatus(Request::STATUS_SUCCESS);
    user->write(req);
}

void ServerManager::clientDisconnected(ConnectionManager* cm) {
    qDebug() << "clientDisconnected - delete";
    m_users.removeOne(cm);

    if(m_disc != nullptr)
        delete m_disc;
    m_disc = cm;
    m_disc->close();
    // TODO : Gérer la déconnexion depuis les tables
}

void ServerManager::readRequest(ConnectionManager *cm)
{
    if(cm->hasRequests())
    {
        this->manageRequest(cm);
    }
}

