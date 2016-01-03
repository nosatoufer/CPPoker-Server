#include "servercontroller.h"

ServerController::ServerController(PokerServerGui* w, ServSocket* serv) :
    m_view(w),
    m_serv(serv)
{}

void ServerController::attachView(PokerServerGui* view) {
    this->m_view = view;
}

void ServerController::attachServer(ServSocket* serv) {
    this->m_serv = serv;
}

void ServerController::addLog(std::string strlog)
{
    this->m_view->log(QString::fromStdString(strlog+"\n"));
}
