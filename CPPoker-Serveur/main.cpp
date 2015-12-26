#include "view/pokerservergui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PokerServerGui w;
    w.show();

    return a.exec();
}
