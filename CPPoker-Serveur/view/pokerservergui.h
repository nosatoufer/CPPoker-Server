#ifndef POKERSERVEURGUI_H
#define POKERSERVEURGUI_H

#include <QMainWindow>
#include "../controller/controller.h"

namespace Ui {
class PokerServerGui;
}
class Controller;

class PokerServerGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit PokerServerGui(QWidget *parent = 0);
    ~PokerServerGui();

    void attachController(Controller* controller);

private:
    Ui::PokerServerGui *ui;
    Controller* controller;

private slots:
    void slotQuitter();
    void slotExecuter();
};

#endif // POKERSERVEURGUI_H
