#ifndef POKERCONTROLLER_H
#define POKERCONTROLLER_H

#include "../view/pokerservergui.h"
#include "../network/servsocket.h"
#include "../model/pokergame.h"
#include "../pattern/observer.h"

/**
 * @brief The PokerController class manages the communication between the PokerManager and the PokerGame
 */
class PokerController
{
protected:
    PokerGame* m_game;

public:
    PokerController(unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind);
    virtual ~PokerController();

    /**
     * @brief allIn tries to play a "AllIn"
     * @param name the player asking to play
     * @return true if the player could do this
     */
    bool allIn(std::string name);

    /**
     * @brief bet tries to play a "bet"
     * @param name the player asking to play
     * @param value the value of the bet
     * @return true if the player could do this
     */
    bool bet(std::string name, unsigned int value);

    /**
     * @brief fold tries to play a "fold"
     * @param name the player asking to play
     * @return true if the player could do this
     */
    bool fold(std::string name);

    /**
     * @brief check tries to play a "check"
     * @param name the player asking to play
     * @return true if the player could do this
     */
    bool check(std::string name);

    /**
     * @brief isPlayerInGame checks if the given player is in game
     * @param nickname the player name
     * @return true if the player is in game
     */
    bool isPlayerInGame(std::string nickname);

    // Ajouter un player
    bool addPlayer(std::string name);

    /**
     * @brief readyToStart checks if the model is ready to start a game
     * @return true if the game is ready to start
     */
    bool readyToStart();

    /**
     * @brief startGame starts the game
     */
    void startGame();

    /**
     * @brief cancelGame stops the game
     */
    void cancelGame();

    /**
     * @brief isGameStarted checks if the game is started
     * @return true if the game is started
     */
    bool isGameStarted();

    /**
     * @brief getCurrentPlayerNickname returns the nickname of the current player
     * @return the nickname of the current player
     */
    std::string getCurrentPlayerNickname();

    /**
     * @brief getPlayerCards returns the pair of cards of the given player name
     * @param nickname the name of the player
     * @return a pair of cards
     */
    std::pair<std::string, std::string> getPlayerCards(std::string nickname);

    /**
     * @brief getMinPlayer returns the minimal amount of player to start the game
     * @return the minimal amount of player to start the game
     */
    unsigned int getMinPlayer();

    /**
     * @brief getMaxPlayerreturns the maximal amount of player allow in the game
     * @return the maximal amount of player allow in the game
     */
    unsigned int getMaxPlayer();

    /**
     * @brief getSmallBlind returns the small blind
     * @return the small blind
     */
    unsigned int getSmallBlind();

    /**
     * @brief getBigBlind returns the big blind
     * @return
     */
    unsigned int getBigBlind();

};

#endif // POKERCONTROLLER_H
