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
    m_Player.insert(player, new ConnectionManager(m_serv->nextPendingConnection(), player, this));
}

void ServSocket::attachController(Controller* controller)
{
    this->controller = controller;
}

bool ServSocket::nicknameAvailable(QString nickname)
{
    bool available = true;
    QMapIterator<Player*, ConnectionManager*> i(m_Player);
    while (i.hasNext() && available) {
        i.next();
        if (i.key()->getNickname() == nickname.toStdString()) {
            available = false;
        }
    }
    return available;
}
