#include "servsocket.h"
#include "connectionmanager.h"

ServSocket::ServSocket(QObject *parent) :
    QObject(parent)
{
    m_serv = new QTcpServer();

    connect(m_serv, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(m_serv->listen(QHostAddress::Any, 1234)) {
        qDebug() << "Server started";

        m_servManager = new ServerManager();
        m_servManager->start();
    } else {
        qDebug() << "Server could not start";
    }
}

ServSocket::~ServSocket()
{
    delete m_servManager;
    delete m_serv;
}

void ServSocket::newConnection()
{
    ConnectionManager* cm = new ConnectionManager(m_serv->nextPendingConnection(),m_servManager);
    m_servManager->addUser(cm);//, this));
}
