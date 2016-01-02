#include "modelcontroller.h"

ModelController::ModelController()
{

}

ModelController::~ModelController()
{
    //delete model;
}

ModelController::ModelController(Room* room) :
    model(room)
{
    room->attachController(this);
}

bool ModelController::allIn(std::string name)
{

}

bool ModelController::call(std::string name)
{

}

bool ModelController::check(std::string name)
{

}

bool ModelController::raise(std::string name)
{

}

bool ModelController::fold(std::string name)
{

}

bool ModelController::addPlayer(std::string name)
{

}

void ModelController::startGame()
{

}

void ModelController::update()
{
    //
}
