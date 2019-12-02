#ifndef WATER_HH
#define WATER_HH

#include "tiles/tilebase.h"
#include "Core/resourcemaps.hh"
#include "Core/gameeventhandler.hh"
#include "Core/objectmanager.hh"

namespace Game {
/**
 * @brief The Water class represents Water in the gameworld.
 *
 *Water has BasicProduction: \n
 * * Money = 3
 * * Food = 8
 * * Wood = 0
 * * Stone = 1
 * * Ore = 0
 *
 * Functionality follows mainly the parent class' functionality.
 *
 * Tile supports 1 buildings.
 */

class Water : public Course::TileBase
{
public:

    /**
     * @brief Disabled parameterless constructor.
     */
    Water() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the student's GameEventHandler.
     */
    Water(const Course::Coordinate& location,
         const std::shared_ptr<Game::GameEventHandler>& eventhandler,
         const std::shared_ptr<Game::ObjectManager>& objectmanager,
         const unsigned int& max_build = 1,
         const unsigned int& max_work = 2,
         const Course::ResourceMap& production = ConstResourceMap::WATER_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Water() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Adds a new building-object to the tile. Building in water adds
     * one hold-marker to the building.
     *
     * Phases: \n
     * 1. Check that there is space for the building. \n
     * 2. Call parent's addBuilding \n
     * 3. Add a HoldMarker for the building. \n
     *
     * @post Exception guarantee: Strong
     * @exception OwnerConflict - If the tile's ownership prevents placing the
     * \b building.
     * @exception NoSpace - If the tile doesn't have enough space for
     * the \b building.
     */
    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Water

} // namespae Game
#endif // WATER_HH
