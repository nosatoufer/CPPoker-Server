#include "pokermanager.h"

PokerManager::PokerManager(QString name, unsigned int minPlayer, unsigned int maxPlayer,
                         unsigned int smallBlind, unsigned int bigBlind) :
    m_players(),
    m_name(name)
{
    m_disc = nullptr;
    m_mController = new PokerController(minPlayer, maxPlayer, smallBlind, bigBlind);
}

PokerManager::~PokerManager()
{
    for(ConnectionManager * player : m_players)
        delete player;
    delete m_mController;
}

void PokerManager::manageRequest(ConnectionManager *player)
{
    Request* req = player->getRequest();
    switch(req->getCommand())
    {
    case GAME_START:
        if (m_mController->readyToStart()) {
            m_mController->startGame();
            req->setStatus("STATUS_SUCCESS");

            this->sendCardsToPlayers();

        } else {
            req->setStatus("STATUS_FAILLURE");
        }
    case POKER_ALL_IN:
        if (m_mController->allIn(player->getNickname()))
            req->setStatus("STATUS_SUCCESS");
        else
            req->setStatus("STATUS_FAILLURE");
        break;
    case POKER_BET:
        if (m_mController->bet(player->getNickname(), std::stoul(req->get("bet"))))
            req->setStatus("STATUS_SUCCESS");
        else
            req->setStatus("STATUS_FAILLURE");
        break;
    case POKER_FOLD:
        if (m_mController->fold(player->getNickname()))
            req->setStatus("STATUS_SUCCESS");
        else
            req->setStatus("STATUS_FAILLURE");
        break;
    case DISCONNECT:
        remPlayer(player);
        break;
    default:
        req->setStatus("STATUS_FAILLURE");

    }
    if (req->getStatus() == "STATUS_SUCCESS")
    {
        sendToAll(req);
    }
    else
    {
        player->write(req);
        delete req;
    }
}

void PokerManager::sendCardsToPlayers()
{
    if (m_mController->isGameStarted()) {
        for(ConnectionManager* p : m_players) {
            Request req;
            req.setCommand(POKER_GIVE_CARD);
            std::pair<std::string, std::string> cards = m_mController->getPlayerCards(p->getNickname());
            qDebug() << "sendCardsToPlayer";
            req.set("cardOne", cards.first);
            req.set("cardTwo", cards.second);
            p->write(&req);
        }
    } else {
        throw PokerManagerException("Erreur lors de l'appel à sendCardsToPlayers() : la partie n'est pas commencée.");
    }
}

void PokerManager::sendToAll(Request *req)
{
    for(ConnectionManager* p : m_players)
        p->write(req);
    delete req;
}

void PokerManager::addPlayer(ConnectionManager *player)
{
    Request * req = new Request();
    req->setCommand(PLAYER_JOINED);
    req->set("pName",player->getNickname());
    sendToAll(req);
    m_players.append(player);
    player->serverToRoom(this);
    m_mController->addPlayer(player->getNickname());

    req = new Request();
    req->setCommand(PLAYER_JOINED);
    qDebug() << m_players.size();
    for(ConnectionManager * p : m_players)
    {
        qDebug() << QString::fromStdString(player->getNickname());
        qDebug() << QString::fromStdString(p->getNickname());
        req->set("pName",p->getNickname());
        qDebug() << "Coucou";
        player->write(req);
        qDebug() << "Coucou";
    }
    delete req;
}

bool PokerManager::remPlayer(ConnectionManager *player)
{
    int i = m_players.indexOf(player);
    if (i != -1)
    {
        m_players.remove(i);
        Request * req = new Request();
        req->setCommand(PLAYER_LEFT);
        req->setMessage(player->getNickname());
        sendToAll(req);
        delete player;
        return true;
    }
    return false;
}

QString PokerManager::name() const
{
    return m_name;
}

int PokerManager::nbPlayer() const
{
    return m_players.size();
}

bool PokerManager::isNicknameAvailable(std::string pName) const
{
    int i = 0;
    bool find = false;
    while(!find && i < m_players.size()) {
        find = (m_players[i]->getNickname() == pName);
        ++i;
    }
    return !find;
}

QVector<std::string> PokerManager::playerName() const
{
    QVector<std::string> playersName;
    for(auto p : m_players)
        playersName.append(p->getNickname());
    return playersName;
}

std::string PokerManager::toString()
{
    std::map<std::string, std::string> map;
    map["name"] = this->m_name.toStdString();
    map["minPlayer"] = std::to_string(this->m_mController->getMinPlayer());
    map["maxPlayer"] = std::to_string(this->m_mController->getMaxPlayer());
    map["smallBlind"] = std::to_string(this->m_mController->getSmallBlind());
    map["bigBlind"] = std::to_string(this->m_mController->getBigBlind());
    map["currentPlayer"] = std::to_string(this->m_players.size());
    return jsonEncode(map);
}

void PokerManager::clientDisconnected(ConnectionManager* cm) {
    qDebug() << "clientDisconnected - delete";
    m_players.removeOne(cm);

    if(m_disc != nullptr)
        delete m_disc;
    m_disc = cm;
    m_disc->close();
    // TODO : Gérer la déconnexion depuis les tables
}

void PokerManager::readRequest(ConnectionManager *cm)
{
    if(cm->hasRequests())
    {
        this->manageRequest(cm);
    }
}

