#ifndef NETOBSERVER_H
#define NETOBSERVER_H

#include "observer.h"

class NetObserver
{
public:
    NetObserver();
    virtual void netUpdate() = 0;
};

#endif // NETOBSERVER_H
