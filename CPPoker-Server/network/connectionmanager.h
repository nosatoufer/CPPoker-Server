#ifndef CONNEXIONMANAGER_H
#define CONNEXIONMANAGER_H

#include <QTcpSocket>
#include <QMap>

#include "player.h"

class connectionManager : public QObject
{
    Q_OBJECT
private:
    QTcpSocket * m_newClient;
    QMap<QString, Player *>* m_players;
public:
    connectionManager(QTcpSocket * newClient, QMap<QString, Player *> *players);
public slots:
    void read();
};

#endif // CONNEXIONMANAGER_H
