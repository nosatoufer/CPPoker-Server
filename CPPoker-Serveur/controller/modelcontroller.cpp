#include "modelcontroller.h"

ModelController::ModelController()
{

}

ModelController::ModelController(Room* room) :
    model(room)
{
    room->attachController(this);
}

void ModelController::update()
{
    //
}
