#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"
#include "../pattern/observer.h"
#include "../model/game.h"


class PokerServerGui;
class ServSocket;

class Controller : public Observer
{
protected:
    PokerServerGui* view;
    ServSocket* serv;


public:
    Controller(PokerServerGui* w, ServSocket* serv);
    void update();
};

#endif // CONTROLLER_H
