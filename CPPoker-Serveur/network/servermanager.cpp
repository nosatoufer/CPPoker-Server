#include "servermanager.h"
#include <QDebug>

ServerManager::ServerManager()
{
    //m_servSocket = new ServSocket();
    m_logs = "Démarrage du serveur \n";
}

ServerManager::~ServerManager()
{
    for(RoomManager * room : m_rooms)
        delete room;
    for(ConnectionManager * user : m_newUsers)
        delete user;
}

void ServerManager::addUser(ConnectionManager *user)
{
    m_logs += "User has joined the server \n";
    m_newUsers.push_back(user);
}

void ServerManager::run()
{
    while(true)
    {
        for(ConnectionManager * user : m_newUsers)
        {
            if (user->hasRequests())
            {
                manageRequest(user);
            }
        }
    }

}

void ServerManager::manageRequest(ConnectionManager *user)
{
    Request * req = user->getRequest();
    switch(user->getRequest()->getCommand())
    {
    case LOGIN:
        if (checkPlayerName(req->getMessage()))
        {
            user->setNickName(req->getMessage());
            req->setStatus("STATUS_SUCCESS");
        }
        else
        {
            req->setStatus("STATUS_FALLURE");
            req->setMessage("Le pseudo est déjà utilisé.");
        }
        break;
    case ROOM_LIST:
        req->setMessage(roomList().toStdString());
        req->setStatus("STATUS_SUCCESS");
        break;

    case ROOM_JOIN:
        if(joinRoom(user, req->getMessage()))
            req->setStatus("STATUS_SUCCESS");
        else
            req->setStatus("STATUS_FAILLURE");
        break;
    case ROOM_CREATE:
        if(createRoom(user, req->getMessage()))
            req->setStatus("STATUS_SUCCESS");
        else
            req->setStatus("STATUS_FAILLURE");

    default:
        req->setStatus("STATUS_FAILLURE");
        req->setMessage("Requête non valide.");
    }
    user->write(req);
    delete req;
}

QString ServerManager::roomList()
{
    QString roomsName = "";
    for(RoomManager * room : m_rooms)
    {
        roomsName += room->name() + " ; " + room->nbPlayer() + " ; ";
    }
    return roomsName;
}

bool ServerManager::createRoom(ConnectionManager * user, std::string name)
{
    if (checkRoomName(name))
        return false;
    m_rooms.append(new RoomManager(name.c_str()));
    return joinRoom(user,name);
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
        m_newUsers.removeOne(user);
        return true;
    }
    return false;
}

bool ServerManager::checkPlayerName(std::string name)
{
    int i = 0;
    bool find = false;
    while( !find && i < m_newUsers.size() )
    {
        find = m_newUsers.at(i++)->getNickname() == name;
    }
    i = 0;
    while( !find && i < m_rooms.size() )
    {
        find = !m_rooms.at(i++)->checkName(name);
    }
    return find;
}


