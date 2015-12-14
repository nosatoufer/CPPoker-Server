/*#include "connectionmanager.h"

connectionManager::connectionManager(QTcpSocket *newClient, QMap<QString, Player *> *players) :
    m_newClient(newClient),
    m_players(players)
{
    connect(newClient, SIGNAL(readyRead()), this, SLOT(read()));
}

void connectionManager::read() // A changer pour la sérialisation
{
    QString name = m_newClient->readAll();
    if(!m_players->contains(name))
    {
        m_players->insert(name, new Player(m_newClient, &name));
    }
}*/

