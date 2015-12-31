#include "controller.h"

Controller::Controller(PokerServerGui* w, ServSocket* serv) :
    view(w),
    serv(serv)
{
    w->attachController(this);
    //serv->attachController(this);
}

void Controller::update()
{
    //
}


