#include "player.h"

Player::Player(QTcpSocket * socket, QString * name) :
    m_socket(socket),
    m_name(name),
    m_stack(0)
{
}

