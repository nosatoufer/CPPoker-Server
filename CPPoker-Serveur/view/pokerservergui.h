#ifndef POKERSERVEURGUI_H
#define POKERSERVEURGUI_H

#include <QMainWindow>
#include "../controller/servercontroller.h"

namespace Ui {
class PokerServerGui;
}
class ServerController;

class PokerServerGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit PokerServerGui(ServerController* servController, QWidget *parent = 0);
    virtual ~PokerServerGui();

    virtual void log(QString log);

protected:
    ServerController* m_servController;
    Ui::PokerServerGui* m_ui;

private slots:
    /**
     * @brief slotQuitter closes the application
     */
    void slotQuitter();

    /**
     * @brief slotExecuter TODO : tries to execute a command on the server
     */
    void slotExecuter();
};

#endif // POKERSERVEURGUI_H
