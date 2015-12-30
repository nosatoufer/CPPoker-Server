#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"
#include "../pattern/observer.h"
#include "../model/game.h"

class Room;
class ServSocket;

class ModelController : public Observer
{
protected:
    Room* model;
    ServSocket* serv;

public:
    ModelController(Room* room, ServSocket* serv);
    void update();
};

#endif // MODELCONTROLLER_H
