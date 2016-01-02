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
