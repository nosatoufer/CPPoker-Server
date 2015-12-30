#include "connectionmanager.h"
#include <QDebug>

ConnectionManager::ConnectionManager(QTcpSocket *newClient, std::string nickname, ServSocket *servSocket) :
    m_sock(newClient),
    servSocket(servSocket),
    nickname(nickname)
{
    qDebug() << "Client connected";
    connect(m_sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(m_sock, SIGNAL(readyRead()), this, SLOT(read()));

    Request req;
    req.setCommand(LOGIN);
    this->write(req);
}

void ConnectionManager::read()
{
    //m_requests.insert(m_requests.begin(), new Request(m_sock->readAll().toStdString()));
    //notify();
    Request request((QString(m_sock->readAll())).toStdString());
    switch (request.getCommand()) {
        case LOGIN:
            if (request.isSet("nickname")) {
                if (servSocket->nicknameAvailable(request.get("nickname"))) {
                    request.setStatus(Request::STATUS_SUCCESS);
                    this->nickname = request.get("nickname");
                    this->write(request.toString());
                    qDebug() << "LOGIN_3";
                } else {
                    request.setStatus(Request::STATUS_FAILURE);
                    this->write(request.toString());
                    qDebug() << "LOGIN_2";
                }
            } else {
                request.setStatus(Request::STATUS_FAILURE);
                this->write(request.toString());
                qDebug() << "LOGIN_1";
            }
        break;
        default:
            qDebug() << "Unknown command";
        break;
    }
}

void ConnectionManager::disconnected()
{
    qDebug() << "Client disconnected";
}

void ConnectionManager::write(Request req)
{
    std::string s = req.toString();
    qDebug() << "SEND : " << QString::fromStdString(s);
    if(m_sock->isWritable())
        m_sock->write(s.c_str(), s.length());
}

std::string ConnectionManager::getNickname()
{
    return this->nickname;
}

/*bool ConnectionManager::hasRequests()
{
    return m_requests.size() != 0;
}

Request * ConnectionManager::getRequest()
{
    Request * c = m_requests.back();
    m_requests.pop_back();
    return c;
}*/
