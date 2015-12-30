#include "modelcontroller.h"

ModelController::ModelController(Room* room, ServSocket* serv) :
    model(room),
    serv(serv)
{
    room->attachController(this);
    serv->attachController(this);
}

void ModelController::update()
{
    //
}
