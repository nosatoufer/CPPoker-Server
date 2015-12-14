#include "pokerserveurgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PokerServeurGui w;
    w.show();

    return a.exec();
}
