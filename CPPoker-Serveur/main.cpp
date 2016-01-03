#include "view/pokerservergui.h"
#include <QApplication>

#include "model/player.h"
#include "model/pokerroom.h"

#include "controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //ServerController* controller = new ServerController(w, serv);
    //PokerServerGui* w = new PokerServerGui();

    ServSocket* serv = new ServSocket();

    //w->show();

    return a.exec();
}
