#ifndef POKERSERVEURGUI_H
#define POKERSERVEURGUI_H

#include <QMainWindow>
#include "../controller/controller.h"
#include "../controller/servercontroller.h"

namespace Ui {
class PokerServerGui;
}
class Controller;
class ServerController;

class PokerServerGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit PokerServerGui(QWidget *parent = 0);
    ~PokerServerGui();

    void attachController(Controller* controller);
    void attachController(ServerController* controller);

private:
    Ui::PokerServerGui *ui;
    Controller* controller;
    ServerController* serverController;

private slots:
    void slotQuitter();
    void slotExecuter();
};

#endif // POKERSERVEURGUI_H
