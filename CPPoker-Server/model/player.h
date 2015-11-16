#ifndef PLAYER_H
#define PLAYER_H

#include <QTcpSocket>

class Player
{
private:
    QTcpSocket * m_socket;
    QString * m_name;
    int m_stack;
public:
    Player(QTcpSocket * socket, QString * name);
};

#endif // PLAYER_H
