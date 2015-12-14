#ifndef POKERSERVEURGUI_H
#define POKERSERVEURGUI_H

#include <QMainWindow>

namespace Ui {
class PokerServeurGui;
}

class PokerServeurGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit PokerServeurGui(QWidget *parent = 0);
    ~PokerServeurGui();

private:
    Ui::PokerServeurGui *ui;

private slots:
    void slotQuitter();
    void slotExecuter();
};

#endif // POKERSERVEURGUI_H
