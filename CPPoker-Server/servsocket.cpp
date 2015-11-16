#include "servsocket.h"

servSocket::servSocket(QObject *parent) :
    QObject(parent)
{
    m_serv = new QTcpServer();

    connect(m_serv, SIGNAL(newConnection()), this, SLOT(newConnection()));


    if(m_serv->listen(QHostAddress::Any, 1234))
        qDebug() << "Server started";
    else
        qDebug() << "Server could not start";



}

void servSocket::newConnection()
{
    QByteArray s = "Hello";
    qDebug() << "New Connection !";
    m_sock = m_serv->nextPendingConnection();
    m_sock->write(s);
    m_sock->flush();

    m_sock->waitForBytesWritten(3000);
    m_sock->close();
}

