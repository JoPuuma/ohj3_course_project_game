#ifndef WATER_HH
#define WATER_HH

#include "tiles/tilebase.h"
#include "Core/resourcemaps.hh"

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
    static const unsigned int MAX_BUILDINGS;
    static const unsigned int MAX_WORKERS;
    static const Course::ResourceMap BASE_PRODUCTION;
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
         const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
         const std::shared_ptr<Course::iObjectManager>& objectmanager,
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
}; // class Water

} // namespae Game
#endif // WATER_HH