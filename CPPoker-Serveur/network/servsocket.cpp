#include "servsocket.h"
#include "connectionmanager.h"

ServSocket::ServSocket(ServerController* servController, QObject *parent) :
    QObject(parent),
    m_servController(servController)
{
    m_serv = new QTcpServer();

    connect(m_serv, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(m_serv->listen(QHostAddress::Any, 1234)) {
        this->m_servController->addLog("Server started");

        m_servManager = new ServerManager(servController);
    } else {
        this->m_servController->addLog("Server could not start");
    }
}

ServSocket::~ServSocket()
{
    delete m_servManager;
    delete m_serv;
}

void ServSocket::newConnection()
{
    m_servManager->addUser(new ConnectionManager(m_serv->nextPendingConnection(),m_servManager));
}
