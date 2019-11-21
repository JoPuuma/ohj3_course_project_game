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

    void addPlayer(std::string name);

private:
    std::map<std::string, std::shared_ptr<Game::Player>> players;
};

} // namespace Game

#endif // GAMEEVENTHANDLER_HH
