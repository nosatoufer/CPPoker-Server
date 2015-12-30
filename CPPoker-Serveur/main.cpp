#include "view/pokerservergui.h"
#include <QApplication>

#include "model/player.h"
#include "model/pokerroom.h"

#include "controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    try
    {

    Player* player1 = new PokerPlayer("Max", 1000);
    Player* player2 = new PokerPlayer("Guillaume", 1000);
    Player* player3 = new PokerPlayer("Thi", 1000);

    std::vector<Player*> players = std::vector<Player*>();
    players.push_back(player1);
    players.push_back(player2);
    players.push_back(player3);

    Room* pokerRoom = new PokerRoom(2, 5, 25, 50, "Partie 1", players);

    Game* game = pokerRoom->startGame();

    std::vector<Card*> cards;

    // Round 1
    static_cast<PokerGame*>(game)->bet(50);

    static_cast<PokerGame*>(game)->bet(25);

    cards = static_cast<PokerGame*>(game)->getTableCard();
    for(int i=0; i<cards.size(); ++i) {
        std::cout << *(cards[i]) << " ";
    }
    std::cout << std::endl;

    // Round 2
    static_cast<PokerGame*>(game)->check();

    static_cast<PokerGame*>(game)->check();

    static_cast<PokerGame*>(game)->check();

    cards = static_cast<PokerGame*>(game)->getTableCard();
    for(int i=0; i<cards.size(); ++i) {
        std::cout << *(cards[i]) << " ";
    }
    std::cout << std::endl;

    // Round 3
    static_cast<PokerGame*>(game)->check();

    static_cast<PokerGame*>(game)->bet(100);

    static_cast<PokerGame*>(game)->bet(100);

    static_cast<PokerGame*>(game)->bet(100);

    cards = static_cast<PokerGame*>(game)->getTableCard();
    for(int i=0; i<cards.size(); ++i) {
        std::cout << *(cards[i]) << " ";
    }
    std::cout << std::endl;

    // Round 4
    static_cast<PokerGame*>(game)->check();

    static_cast<PokerGame*>(game)->bet(100);

    static_cast<PokerGame*>(game)->bet(100);

    static_cast<PokerGame*>(game)->bet(100);

    cards = static_cast<PokerGame*>(game)->getTableCard();

    for(int i=0; i<cards.size(); ++i) {
        std::cout << *(cards[i]) << " ";
    }

    std::cout << std::endl;

    static_cast<PokerGame*>(game)->bet(100); // Génère une exception : normal, partie terminée !

    } catch(std::exception const& e) {
        std::cerr << "ERREUR : " << e.what() << std::endl;
    }
    */

    PokerServerGui* w = new PokerServerGui();
    ServSocket* serv = new ServSocket();

    ServerController* controller = new ServerController(w, serv);

    w->show();

    return a.exec();
}
