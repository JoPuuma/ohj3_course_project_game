#ifndef SAND_HH
#define SAND_HH

#include "tiles/tilebase.h"
#include "Core/resourcemaps.hh"
#include "Core/gameeventhandler.hh"
#include "Core/objectmanager.hh"

namespace Game {
/**
 * @brief The Sand class represents Sand in the gameworld.
 *
 * Sand has BasicProduction: \n
 * * Money = 2
 * * Food = 1
 * * Wood = 1
 * * Stone = 1
 * * Ore = 0
 *
 * Functionality follows mainly the parent class' functionality.
 *
 * Tile supports 2 buildings.
 */

class Sand : public Course::TileBase
{
public:

    /**
     * @brief Disabled parameterless constructor.
     */
    Sand() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the student's GameEventHandler.
     */
    Sand(const Course::Coordinate& location,
         const std::shared_ptr<Game::GameEventHandler>& eventhandler,
         const std::shared_ptr<Game::ObjectManager>& objectmanager,
         const unsigned int& max_build = 2,
         const unsigned int& max_work = 3,
         const Course::ResourceMap& production = ConstResourceMap::SAND_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Sand() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Sand

} // namescape Game



#endif // SAND_HH
