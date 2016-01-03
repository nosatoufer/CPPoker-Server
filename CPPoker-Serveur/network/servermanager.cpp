#include "servermanager.h"
#include <QDebug>

ServerManager::ServerManager() :
    m_users(),
    m_rooms()
{
    m_logs = "Démarrage du ServerManager \n";
    qDebug() << "Démarrage du ServerManager";
}

ServerManager::~ServerManager()
{
    for(RoomManager * room : m_rooms)
        delete room;
    for(ConnectionManager * user : m_users)
        delete user;
}

void ServerManager::addUser(ConnectionManager *user)
{
    m_logs += "User has joined the server \n";
    // qDebug() << "User joining the server";
    m_users.push_back(user);
    qDebug() << "User has joined the server";
}

void ServerManager::run()
{
    while(true)
    {
        for(ConnectionManager* user : m_users)
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
    }
}

void ServerManager::manageRequest(ConnectionManager *user)
{
    qDebug() << "Managing request";
    Request* req = user->getRequest();
    switch(req->getCommand())
    {
    // qDebug() << "Treating request ...";
    case LOGIN:
        qDebug() << "Login Request";
        if (isNicknameAvailable(req->getMessage()))
        {
            user->setNickName(req->getMessage());
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
        req->setMap("rooms", this->roomList());
        req->setStatus(Request::STATUS_SUCCESS);
        user->write(req);
        break;

    case ROOM_CREATE:
        if(createRoom(req->get("name"),
                      std::stoul(req->get("minPlayer")),
                      std::stoul(req->get("maxPlayer")),
                      std::stoul(req->get("smallBlind")),
                      std::stoul(req->get("bigBlind")))) {
            req->setStatus(Request::STATUS_SUCCESS);
        } else {
            req->setStatus(Request::STATUS_FAILURE);
        }
        user->write(req);
        break;

    case ROOM_JOIN:
        if(joinRoom(user, req->getMessage())) {
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
    for(RoomManager * room : m_rooms)
    {
        map["room"+std::to_string(i)] = room->toString();
    }
    return map;
}

bool ServerManager::createRoom(std::string name, unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind)
{
    if (checkRoomName(name))
        return false;
    RoomManager* rm = new RoomManager(QString::fromStdString(name), minPlayer, maxPlayer, smallBlind, bigBlind);
    m_rooms.append(rm);
    rm->start();
    return true;
}

bool ServerManager::checkRoomName(std::string name)
{
    int i = 0;
    while( i < m_rooms.size() && m_rooms.at(i)->name().toStdString() != name);
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

void ServerManager::clientDisconnected(ConnectionManager* cm) {
    int i = -1;
    bool find = false;
    do
    {
        ++i;
        find = (m_users.at(i) == cm);
    } while(!find && i < m_users.size()-1);
    if (find) {
        m_users.remove(i);
        delete cm;
    }

    // TODO : Gérer la déconnexion depuis les tables
}

