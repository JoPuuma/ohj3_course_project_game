#ifndef ROCK_HH
#define ROCK_HH

#include "tiles/tilebase.h"

namespace Game {
/**
 * @brief The Rock class represents Rockland in the gameworld.
 *
 * Rock has BasicProduction: \n
 * * Money =
 * * Food =
 * * Wood =
 * * Stone =
 * * Ore =
 *
 * Functionality follows mainly the parent class' functionality.
 *
 * Tile supports ? buildings.
 */
// lisää basicproduction arvot
class Rock : public Course::TileBase
{
public:
    static const unsigned int MAX_BUILDINGS;
    static const unsigned int MAX_WORKERS;
    static const Course::ResourceMap BASE_PRODUCTION;
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
         const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
         const std::shared_ptr<Course::iObjectManager>& objectmanager,
         const unsigned int& max_build = 3,
         const unsigned int& max_work = 3,
         const Course::ResourceMap& production = Course::ConstResourceMaps::GRASSLAND_BP); // tiedot pitää muuttaa.

    /**
     * @brief Default destructor.
     */
    virtual ~Rock() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

}; // class Rock


} // namespace Game


#endif // ROCK_HH
