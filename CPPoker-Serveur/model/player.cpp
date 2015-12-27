#include "player.h"

Player::Player(std::string nickname, int cash) :
    nickname(nickname),
    cash(cash)
{}

int Player::getCash() {
    return this->cash;
}

void Player::setCash(int cash) {
    this->cash = cash;
}

std::string Player::getNickname() {
    return this->nickname;
}

void Player::setNickname(std::string nickname) {
    this->nickname = nickname;
}

/*Player::Player(QTcpSocket * socket, QString * name) :
    m_socket(socket),
    m_name(name),
    m_stack(0)
{
}*/

