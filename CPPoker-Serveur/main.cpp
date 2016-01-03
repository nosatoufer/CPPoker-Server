#include "view/pokerservergui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ServerController* servController = new ServerController();
    PokerServerGui* w = new PokerServerGui(servController);
    ServSocket* serv = new ServSocket(servController);

    w->show();

    return a.exec();
}
