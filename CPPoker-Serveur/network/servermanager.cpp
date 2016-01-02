#include "servermanager.h"
#include <QDebug>

ServerManager::ServerManager()
{
    //m_servSocket = new ServSocket();
}

void ServerManager::addUser(ConnectionManager *user)
{
    qDebug() << "User has joined the server";
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
                manageRequest(user->getRequest());
            }
        }
    }

}

void ServerManager::manageRequest(Request *req)
{
    switch(req->getCommand())
    {
    case LOGIN:
        checkName(req->getMessage());
        break;

    }
}

bool ServerManager::checkName(std::string name)
{
    uint i = 0;
    while( i < m_rooms.size() && !m_rooms.at(i++)->checkName(name));
    return i < m_rooms.size();
}


