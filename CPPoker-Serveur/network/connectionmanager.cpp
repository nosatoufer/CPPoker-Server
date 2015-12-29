#include "connectionmanager.h"

ConnectionManager::ConnectionManager(QTcpSocket *newClient, Player* player, ServSocket *servSocket) :
    client(newClient),
    servSocket(servSocket),
    player(player)
{
    connect(newClient, SIGNAL(readyRead()), this, SLOT(read()));
}

void ConnectionManager::read()
{
    Request request(client->readAll());

    switch (request.getCommand()) {
        case LOGIN:
            if(servSocket->nicknameAvailable(request.get("nickname")))
            {
                player->setNickname(request.get("nickname"));
            }
            break;
    }
}
