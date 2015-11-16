#ifndef SERVSOCKET_H
#define SERVSOCKET_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QMap>

#include "player.h"

class ServSocket : public QObject
{
    Q_OBJECT
private:
    QTcpServer * m_serv;
    QTcpSocket * m_sock;
    QMap<QString, Player *> m_Player;

public:
    explicit ServSocket(QObject *parent = 0);
public slots:
    void newConnection();
};

#endif // SERVSOCKET_H
