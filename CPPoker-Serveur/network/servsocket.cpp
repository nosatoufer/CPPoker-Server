#include "servsocket.h"
#include "connectionmanager.h"

ServSocket::ServSocket(QObject *parent) :
    QObject(parent)
{
    m_serv = new QTcpServer();

    connect(m_serv, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(m_serv->listen(QHostAddress::Any, 1234))
        qDebug() << "Server started";
    else
        qDebug() << "Server could not start";

}

void ServSocket::newConnection()
{
    Player* player = new Player();
    m_player.insert(player, new ConnectionManager(m_serv->nextPendingConnection(), player, this));
}

void ServSocket::attachController(Controller* controller)
{
    this->controller = controller;
}

bool ServSocket::nicknameAvailable(std::string nickname)
{
    bool available = true;
    QMapIterator<Player*, ConnectionManager*> i(m_player);
    while (i.hasNext() && available) {
        i.next();
        if (i.key()->getNickname() == nickname) {
            available = false;
        }
    }
    return available;
}
