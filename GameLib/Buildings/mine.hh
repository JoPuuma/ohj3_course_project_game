#ifndef MINE_HH
#define MINE_HH

#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"


namespace Game {

/**
 * @brief The Mine class represents a mine-building in the game.
 *
 * The Mine adds  base-production for .
 */
class Mine : public Course::BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Mine() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param tile points to the tile upon which the building is constructed.
     *
     * @post Exception Guarantee: No guarantee.
     * @exception OwnerConflict - if the building conflicts with tile's
     * ownership.
     */
    explicit Mine(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Course::ConstResourceMaps::FARM_BUILD_COST,
            const Course::ResourceMap& production = Course::ConstResourceMaps::FARM_PRODUCTION
            );  // muuta cost and product oikeaksi.

    /**
     * @brief Default destructor.
     */
    virtual ~Mine() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;


}; // class Mine

}  // namespace Game


#endif // MINE_HH
