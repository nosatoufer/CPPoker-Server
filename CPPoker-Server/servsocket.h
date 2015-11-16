#ifndef SERVSOCKET_H
#define SERVSOCKET_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>


class servSocket : public QObject
{
    Q_OBJECT
private:
    QTcpServer * m_serv;
    QTcpSocket * m_sock;

public:
    explicit servSocket(QObject *parent = 0);
public slots:
    void newConnection();
};

#endif // SERVSOCKET_H
