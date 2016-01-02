#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"
#include "../pattern/observer.h"
#include "../model/game.h"


class Room;

class ModelController : public Observer
{
protected:
    Room* model;

public:
    ModelController();
    ~ModelController();
    ModelController(Room* room);
    void update();
};

#endif // MODELCONTROLLER_H
