#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"
#include "../pattern/observer.h"
#include "../model/game.h"

class PokerServerGui;
class ServSocket;

class ServerController : public Observer
{
protected:
    PokerServerGui* view;
    ServSocket* serv;

public:
    ServerController(PokerServerGui* w, ServSocket* serv);
    void update();
};

#endif // SERVERCONTROLLER_H
