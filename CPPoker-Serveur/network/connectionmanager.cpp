#include "connectionmanager.h"
#include <QDebug>

ConnectionManager::ConnectionManager(QTcpSocket *newClient, ServerManager* sm) :
    m_sock(newClient),
    mutex(),
    m_requests(),
    nickname("guest")
{
    qDebug() << "Client connected";
    connect(m_sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(m_sock, SIGNAL(readyRead()), this, SLOT(read()));
    connect(this, SIGNAL(clientDisconnected(ConnectionManager*)), sm, SLOT(clientDisconnected(ConnectionManager*)));

    Request * req = new Request();
    req->setCommand(LOGIN);
    this->write(req);
    delete req;
}

ConnectionManager::~ConnectionManager()
{
    disconnect(m_sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    disconnect(m_sock, SIGNAL(readyRead()), this, SLOT(read()));
    m_sock->close();
    delete m_sock;
    for(Request * req : m_requests)
        delete req;

}

void ConnectionManager::read()
{
    //mutex.lock();
    QString req(m_sock->readAll());
    qDebug() << "Request received : " << req;
    m_requests.insert(m_requests.begin(), new Request(req.toStdString()));
    //mutex.unlock();
}

void ConnectionManager::disconnected()
{
    qDebug() << "Client disconnected";
    emit clientDisconnected(this);
}

void ConnectionManager::write(Request * req)
{
    if(m_sock->isWritable())
    {
        std::string s = req->toString();
        qDebug() << "SEND : " << QString::fromStdString(s);
        m_sock->write(s.c_str(), s.length());
        //qDebug() << "SENT" << QString::fromStdString(s);
    }
}

void ConnectionManager::setNickName(std::string name)
{
    this->nickname = name;
}

std::string ConnectionManager::getNickname()
{
    return this->nickname;
}

bool ConnectionManager::hasRequests()
{
    //qDebug() << "Enter hasRequests";
    //mutex.lock();
    //qDebug() << "Middle hasRequests";
    bool returnValue = (m_requests.size() != 0);
    //qDebug() << "Exiting hasRequests";
    //mutex.unlock();
    return returnValue;
}

Request * ConnectionManager::getRequest()
{
    //mutex.lock();
    //qDebug() << "Entering getRequests";
    Request * req = m_requests.back();
    m_requests.pop_back();
    //qDebug() << "Exiting getRequests";
    //mutex.unlock();
    return req;
}
