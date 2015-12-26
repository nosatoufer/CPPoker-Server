#ifndef POKERSERVEURGUI_H
#define POKERSERVEURGUI_H

#include <QMainWindow>

namespace Ui {
class PokerServerGui;
}

class PokerServerGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit PokerServerGui(QWidget *parent = 0);
    ~PokerServerGui();

private:
    Ui::PokerServerGui *ui;

private slots:
    void slotQuitter();
    void slotExecuter();
};

#endif // POKERSERVEURGUI_H
