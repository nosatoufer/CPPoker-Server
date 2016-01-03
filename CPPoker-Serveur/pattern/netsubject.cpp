#include "netsubject.h"

NetSubject::NetSubject()
{
}

void NetSubject::addObserver(NetObserver *obs)
{
    m_observers.push_back(obs);
}

void NetSubject::remObserver(NetObserver *obs)
{
    int i = m_observers.indexOf(obs);
    m_observers.remove(i);
}

void NetSubject::notify()
{
    for(NetObserver * obs : m_observers )
    {
        obs->netUpdate();
    }
}

