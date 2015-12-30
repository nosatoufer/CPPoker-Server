#include "servercontroller.h"

ServerController::ServerController(PokerServerGui* w, ServSocket* serv) :
    view(w),
    serv(serv)
{
    w->attachController(this);
    serv->attachController(this);
}

void ServerController::update()
{
    //
}


