#ifndef WORLDGENERATOR_HH
#define WORLDGENERATOR_HH

#include "functional"
#include "map"
#include "memory"

#include "Core/gameeventhandler.hh"
#include "Core/objectmanager.hh"
#include "tiles/tilebase.h"



namespace Game {

using TileConstructorPointer = std::function<std::shared_ptr<Course::TileBase>(
    Course::Coordinate,
    std::shared_ptr<GameEventHandler>,
    std::shared_ptr<ObjectManager>)>;

/**
 * @brief The WorldGenerator class is a singleton for generating tiles
 * for the game.
 *
 * Create new Tile-objects that form the gameworld. \n
 * Usage:
 * 1. Use WorldGenerator::getInstance() to get a reference to the singleton.
 * 2. Call addConstructor with each Tile type you created.
 * 3. Generate the map through the reference.
 */
class WorldGenerator
{
public:
    /**
     * @brief Used to get a reference to the Singleton instance.
     * @return Reference to the Singleton instance.
     * @post Exception guarantee: No-throw
     */
    static WorldGenerator& getInstance();

     // Prevent copy and move construction and assignment.
    WorldGenerator(const WorldGenerator&) = delete;
    WorldGenerator& operator=(const WorldGenerator&) = delete;
    WorldGenerator(WorldGenerator&&) = delete;
    WorldGenerator& operator=(WorldGenerator&&) = delete;


    /**
     * @brief Register a Tile's constructor for use in map generation.
     * @note Do this only once per Tile type or they won't be equally common.
     * Use the Tile's type as the template parameter: addConstructor<Forest>();
     * @param n represents the type of the Tile from referenceMap.
     */
    template<typename T>
    void addConstructor(char n)
    {
        TileConstructorPointer ctor = std::make_shared<T, Course::Coordinate,
                std::shared_ptr<GameEventHandler>,
                std::shared_ptr<ObjectManager> >;
        m_ctors.insert(std::make_pair(n, ctor));
    }
    /**
     * @brief Generates Tile-objects and sends them to ObjectManager.
     * @param size_x is the horizontal size of the map area.
     * @param size_y is the vertical size of the map area.
     * @param ObjectManager points to the ObjectManager that receives the
     * generated Tiles.
     * @param EventHandler points to the student's GameEventHandler.
     * @post Exception guarantee: No-throw
     */
    void generateMap(unsigned int size_x,
                     unsigned int size_y,
                     const std::shared_ptr<ObjectManager>& ObjectManager,
                     const std::shared_ptr<GameEventHandler>& EventHandler);



private:
    /**
     * @brief Default constructor.
     */
    WorldGenerator() = default;

    /**
     * @brief Default destructor.
     */
    ~WorldGenerator() = default;

    /**
     * @brief Greates the referenceMap.
     */
    void greateReferenceMap();

    std::vector<std::vector<char>> referenceMap = {};

    std::map<char, TileConstructorPointer> m_ctors;

}; // class WorldGenerator

} // namespace Game

#endif // WORLDGENERATOR_HH
