#include "view/pokerservergui.h"
#include <QApplication>

#include "model/player.h"
#include "model/pokerroom.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Player* player1 = new PokerPlayer("Max", 1000);
    Player* player2 = new PokerPlayer("Guillaume", 1000);
    Player* player3 = new PokerPlayer("Thi", 1000);

    std::vector<Player*> players = std::vector<Player*>();
    players.push_back(player1);
    players.push_back(player2);
    players.push_back(player3);

    Room* pokerRoom = new PokerRoom(2, 5, 25, 50, "Partie 1", players);

    Game* game = pokerRoom->startGame();

    // Round 1
    static_cast<PokerGame*>(game)->bet(50);

    static_cast<PokerGame*>(game)->bet(25);

    // Round 2
    static_cast<PokerGame*>(game)->check();

    static_cast<PokerGame*>(game)->check();

    static_cast<PokerGame*>(game)->check();

    // Round 3
    static_cast<PokerGame*>(game)->check();

    static_cast<PokerGame*>(game)->bet(100);

    static_cast<PokerGame*>(game)->bet(100);

    static_cast<PokerGame*>(game)->bet(100);


    PokerServerGui w;
    w.show();

    return a.exec();
}
