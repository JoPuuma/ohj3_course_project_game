#ifndef GAMEEVENTHANDLER_HH
#define GAMEEVENTHANDLER_HH
#include <map>
#include <memory>

#include "interfaces/igameeventhandler.h"
#include "player.hh"
#include "Core/objectmanager.hh"
#include "core/basicresources.h"


namespace Game{

class ObjectManager;
/**
 * @brief The GameEventHandler class
 */
class GameEventHandler: public Course::iGameEventHandler
{
public:
    const int MAX_ROUND_OFF = -1; // default value for max round

    GameEventHandler();
    /**
     * @brief Modify Player's resource. Can be used to both sum or subtract.
     * @param player Pointer to the Player whose resource is being modified.
     * @param resource Defines the modified resource.
     * @param amount Defines the amount of change.
     * @post Exception guarantee: Basic
     * @return
     * True - Modification was succesful. \n
     * False - Modification failed. \n
     */
    virtual bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                Course::BasicResource resource,
                                int amount);

    /**
     * @brief Modify Player's resources. Can be used to both sum or subtract
     * @param player Pointer to the Player whose resources are being modified.
     * @param resources ResourceMap containing change amounts.
     * @return
     * True - Modification was succesful. \n
     * False - Modification failed. \n
     */
    virtual bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                 Course::ResourceMap resources);

    /**
     * @brief Creates five basic workers for all players
     * @param eventhandler
     * @param objectmanager
     */
    void addBasicWorkers(std::shared_ptr<Game::GameEventHandler>& eventhandler,
                         std::shared_ptr<Game::ObjectManager>& objectmanager);
    /**
     * @brief initializeGame
     * @param players: player names as strings
     * @param eventhandler
     * @param objectmanager
     * @param rounds: contain max round value. Not in use by default.
     * @pre players length two or over
     * @post exeption guarantee: basic
     */
    void initializeGame(const std::vector<std::string>& players,
                        std::shared_ptr<Game::GameEventHandler>& eventhandler,
                        std::shared_ptr<Game::ObjectManager>& objectmanager,
                        const int& rounds = -1);
    /**
     * @brief getRound
     * @return current round number
     * @post exeption guarantee: no-throw
     */
    unsigned int getRound();

    /**
     * @brief currentPlayer
     * @return pointer to the player who is in turn
     * @post exeption guarantee: no-throw
     */
    std::shared_ptr<Game::Player> currentPlayer();

    /**
     * @brief Handles turn changing
     * @post exeption guarantee: no-throw
     */
    void endTurn();

    /**
     * @brief gameEnd
     * @param objectmanager
     * @return
     * True - max rounds played or all tiles have owner or played over 200 rounds
     */
    bool gameEnd(std::shared_ptr<Game::ObjectManager>& objectmanager);

    /**
     * @brief determineWinner, merge all player resources and compare them
     * @return name of the winner
     */
    std::string determineWinner();

    /**
     * @brief number of moves per one turn
     */
    int maxMoves = 0;

private:
    std::vector<std::shared_ptr<Game::Player>> playerPtrs = {};
    std::shared_ptr<Game::Player> eInTurn = nullptr; // current player
    int round_; // current round
    int maxRound_;
    std::vector<int> playerColors;
};

} // namespace Game

#endif // GAMEEVENTHANDLER_HH
