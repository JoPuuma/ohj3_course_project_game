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
     * @param players
     * @param eventhandler
     * @param objectmanager
     * @param rounds
     */
    void initializeGame(const std::vector<std::string>& players,
                        std::shared_ptr<Game::GameEventHandler>& eventhandler,
                        std::shared_ptr<Game::ObjectManager>& objectmanager,
                        const int& rounds = -1);
    unsigned int getRound();

    std::shared_ptr<Game::Player> currentPlayer();

    void endTurn();

    /**
     * @brief gameEnd
     * @param objectmanager
     * @return
     */
    bool gameEnd(std::shared_ptr<Game::ObjectManager>& objectmanager);

    /**
     * @brief determineWinner
     * @return name of the winner
     */
    std::string determineWinner();

    /**
     * @brief Count of moves per one turn
     */
    int maxMoves = 0;

private:
    std::vector<std::shared_ptr<Game::Player>> playerPtrs = {};
    std::shared_ptr<Game::Player> eInTurn = nullptr;
    int round_;         // current round
    int maxRound_;
    std::vector<int> playerColors;
};

} // namespace Game

#endif // GAMEEVENTHANDLER_HH
