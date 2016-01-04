#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"

class PokerServerGui;
class ServSocket;

/**
 * @brief The ServerController class manages the communication between the ServerManager and the view
 */
class ServerController
{
protected:
    PokerServerGui* m_view;
    ServSocket* m_serv;

public:
    ServerController(PokerServerGui* w = nullptr, ServSocket* serv = nullptr);

    /**
     * @brief attachView attaches a view to the controller
     * @param view the view to attach
     */
    virtual void attachView(PokerServerGui* view);

    /**
     * @brief attachServer attaches a ServSocket to the controller
     * @param serv the ServSocket to attach
     */
    virtual void attachServer(ServSocket* serv);

    virtual void addLog(std::string log);
};

#endif // SERVERCONTROLLER_H
