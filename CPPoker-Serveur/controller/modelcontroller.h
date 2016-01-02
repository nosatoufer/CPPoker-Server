#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"
#include "../pattern/observer.h"
#include "../model/game.h"


class Room;

class ModelController : public Observer
{
protected:
    Room* model;

public:
    ModelController();
    ~ModelController();
    ModelController(Room* room);

    // TODO :
    // Les différentes option de jeu d'un joueur
    bool allIn(std::string name);
    bool call(std::string name);
    bool check(std::string name);
    bool raise(std::string name);
    bool fold(std::string name);

    // Ajoute un player quand la room ajoute un joueur
    bool addPlayer(std::string name);

    void startGame();


    void update();
};

#endif // MODELCONTROLLER_H
