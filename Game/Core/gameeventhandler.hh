#ifndef GAMEEVENTHANDLER_HH
#define GAMEEVENTHANDLER_HH
#include <map>

#include "interfaces/igameeventhandler.h"
#include "player.hh"
#include "core/basicresources.h"


namespace Game{

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

    void addPlayer(std::string name,
                   std::shared_ptr<Game::Player> ptr);
    void initializeGame(const std::vector<std::string>& players,
                        const int& rounds = -1);
    unsigned int getRound();
    std::shared_ptr<Game::Player> currentPlayer();
    void endTurn();
    bool gameEnd();

private:
    std::map<std::string, std::shared_ptr<Game::Player>> players;
    std::vector<std::shared_ptr<Game::Player>> playerPtrs = {};
    std::shared_ptr<Game::Player> eInTurn = nullptr;
    int round_;
    int maxRound_;
};

} // namespace Game

#endif // GAMEEVENTHANDLER_HH
