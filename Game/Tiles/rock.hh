#ifndef ROCK_HH
#define ROCK_HH

#include "tiles/tilebase.h"
#include "Core/resourcemaps.hh"
#include "Core/gameeventhandler.hh"
#include "Core/objectmanager.hh"


namespace Game {
/**
 * @brief The Rock class represents Rockland in the gameworld.
 *
 * Rock has BasicProduction: \n
 * * Money = 10
 * * Food = 0
 * * Wood = 0
 * * Stone = 10
 * * Ore = 5
 *
 * Functionality follows mainly the parent class' functionality.
 *
 * Tile supports 2 buildings.
 */

class Rock : public Course::TileBase
{
public:

    /**
     * @brief Disabled parameterless constructor.
     */
    Rock() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the student's GameEventHandler.
     */
    Rock(const Course::Coordinate& location,
         const std::shared_ptr<Game::GameEventHandler>& eventhandler,
         const std::shared_ptr<Game::ObjectManager>& objectmanager,
         const unsigned int& max_build = 1,
         const unsigned int& max_work = 3,
         const Course::ResourceMap& production = ConstResourceMap::ROCK_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Rock() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Rock


} // namespace Game


#endif // ROCK_HH
