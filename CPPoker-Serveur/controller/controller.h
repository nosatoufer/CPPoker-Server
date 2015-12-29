#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"

class PokerServerGui;
class ServSocket;

class Controller
{
protected:
    PokerServerGui* view;
    ServSocket* serv;

public:
    Controller(PokerServerGui* w, ServSocket* serv);
};

#endif // CONTROLLER_H
