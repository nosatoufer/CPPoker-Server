#include "servsocket.h"
#include "connectionmanager.h"

ServSocket::ServSocket(QObject *parent) :
    QObject(parent)
{
    m_servManager = new ServerManager();
    m_serv = new QTcpServer();

    connect(m_serv, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(m_serv->listen(QHostAddress::Any, 1234))
        qDebug() << "Server started";
    else
        qDebug() << "Server could not start";

}

void ServSocket::newConnection()
{
    m_servManager->addUser(new ConnectionManager(m_serv->nextPendingConnection()));//, this));
}
/*
void ServSocket::attachController(Controller* controller)
{
    this->controller = controller;
}

void ServSocket::attachController(ModelController* controller)
{
    this->modelController.push_back(controller);
}

void ServSocket::attachController(ServerController* controller)
{
    this->serverController = controller;
}

bool ServSocket::nicknameAvailable(std::string nickname)
{
    bool available = true;
    unsigned int i = 0;
    while (i < m_player.size() && available) {
        if (m_player[i]->getNickname() == nickname) {
            available = false;
        }
        ++i;
    }
    return available;
}
*/
