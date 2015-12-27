#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "playerexception.h"

class Player
{
protected:
    std::string nickname;
    int cash;
public:
    Player(std::string nickname, int cash=0);

    int getCash();
    void setCash(int cash);

    std::string getNickname();
    void setNickname(std::string nickname);
};

/*#include <QTcpSocket>

class Player
{
private:
    QTcpSocket * m_socket;
    QString * m_name;
    int m_stack;
public:
    Player(QTcpSocket * socket, QString * name);
};*/

#endif // PLAYER_H
