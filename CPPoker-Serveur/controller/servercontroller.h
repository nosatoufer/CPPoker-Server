#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"

class PokerServerGui;
class ServSocket;

class ServerController
{
protected:
    PokerServerGui* m_view;
    ServSocket* m_serv;

public:
    ServerController(PokerServerGui* w = nullptr, ServSocket* serv = nullptr);

    virtual void attachView(PokerServerGui* view);
    virtual void attachServer(ServSocket* serv);

    virtual void addLog(std::string log);
};

#endif // SERVERCONTROLLER_H
