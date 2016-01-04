#include "connectionmanager.h"
#include <QDebug>

ConnectionManager::ConnectionManager(QTcpSocket *newClient, ServerManager* sm) :
    m_sock(newClient),
    m_requests(),
    m_nickname("guest")
{
    qDebug() << "Client connecting";
    connect(m_sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(m_sock, SIGNAL(readyRead()), this, SLOT(read()));
    connect(this, SIGNAL(clientDisconnected(ConnectionManager*)), sm, SLOT(clientDisconnected(ConnectionManager*)));
    connect(this, SIGNAL(newRequest(ConnectionManager*)), sm, SLOT(readRequest(ConnectionManager*)));
    qDebug() << "Client connected";

    Request * req = new Request();
    req->setCommand(LOGIN);
    this->write(req);
    delete req;
}

ConnectionManager::~ConnectionManager()
{
    qDebug() << "~ConnectionManager()";
    this->disconnect();
    delete m_sock;
    for(Request * req : m_requests)
        delete req;
    qDebug() << "~ConnectionManager() 2";
}

void ConnectionManager::read()
{
    QRegExp rex("[|]");
    QString s(m_sock->readAll());
    QStringList list = s.split(rex, QString::SkipEmptyParts);
    for(QString req : list)
    {
        qDebug() << "Request received : " << req;
        m_requests.insert(m_requests.begin(), new Request(req.toStdString()));
    }
    emit newRequest(this);
}

void ConnectionManager::disconnected()
{
    qDebug() << "Client disconnected";
    emit clientDisconnected(this);
}

void ConnectionManager::write(Request * req)
{
    if(m_sock->isOpen() && m_sock->isWritable())
    {
        std::string s = req->toString();
        s+="|";
        qDebug() << "SEND " << QString::fromStdString(m_nickname) << " : " << QString::fromStdString(s);
        m_sock->write(s.c_str(), s.length());
    }
}

void ConnectionManager::setNickName(std::string name)
{
    this->m_nickname = name;
}

std::string ConnectionManager::getNickname()
{
    qDebug() << "getNickname()";
    return this->m_nickname;
}

bool ConnectionManager::hasRequests()
{
    return (m_requests.size() != 0);
}

Request * ConnectionManager::getRequest()
{
    Request * req = m_requests.back();
    m_requests.pop_back();
    return req;
}

void ConnectionManager::close()
{
    m_sock->close();
}

void ConnectionManager::serverToRoom(PokerManager *room)
{
    disconnect(this, SIGNAL(clientDisconnected(ConnectionManager*)), 0, 0);
    disconnect(this, SIGNAL(newRequest(ConnectionManager*)), 0, 0);

    connect(this, SIGNAL(clientDisconnected(ConnectionManager*)), room, SLOT(clientDisconnected(ConnectionManager*)));
    connect(this, SIGNAL(newRequest(ConnectionManager*)), room, SLOT(readRequest(ConnectionManager*)));
}
