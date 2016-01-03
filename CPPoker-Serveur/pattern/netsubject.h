#ifndef NETSUBJECT_H
#define NETSUBJECT_H

#include "netobserver.h"
#include <QVector>


class NetSubject
{
private:
    QVector<NetObserver*> m_observers;
public:
    NetSubject();
    void addObserver(NetObserver * obs);
    void remObserver(NetObserver * obs);
    void notify();
};

#endif // NETSUBJECT_H
