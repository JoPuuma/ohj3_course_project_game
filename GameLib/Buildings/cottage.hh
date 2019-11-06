#ifndef COTTAGE_HH
#define COTTAGE_HH

#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"

namespace Game {

/**
 * @brief The Cottage class represents a cottage-building in the game.
 *
 * The Cottage adds  base-production for .
 */
class Cottage : public Course::BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Cottage() = delete;

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
    explicit Cottage(
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
    virtual ~Cottage() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

}; // class Cottage

} // namespace Game


#endif // COTTAGE_HH
