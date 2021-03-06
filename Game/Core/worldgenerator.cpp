#include "worldgenerator.hh"

#include "Tiles/rock.hh"
#include "Tiles/sand.hh"
#include "Tiles/water.hh"
#include "tiles/forest.h"

#include "vector"


namespace Game {

WorldGenerator& WorldGenerator::getInstance()
{
    static WorldGenerator instance;
    return instance;
}




void WorldGenerator::generateMap(
        unsigned int size_x,
        unsigned int size_y,
        const std::shared_ptr<ObjectManager>& objectmanager,
        const std::shared_ptr<GameEventHandler>& eventhandler)
{
    greateReferenceMap();
    std::vector<std::shared_ptr<Course::TileBase>> tiles;

    for (unsigned int x = 0; x < size_x; ++x)
    {
        for (unsigned int y = 0; y < size_y; ++y)
        {
            for (const auto&ctor : m_ctors)
            {
                if (ctor.first == referenceMap[y][x])
                {
                 tiles.push_back(ctor.second(Course::Coordinate(x, y), eventhandler, objectmanager));

                }
            }

        }
    }

    objectmanager->addTiles(tiles);

}


void WorldGenerator::greateReferenceMap()
{
       referenceMap = {
        {'f', 'r', 's', 'w', 'w', 'f', 'r'},
        {'f', 'r', 's', 'w', 'f', 'f', 'r'},
        {'f', 'f', 's', 'w', 'f', 'f', 'f'},
        {'f', 's', 'w', 'w', 'f', 's', 'f'},
        {'f', 's', 'w', 's', 's', 's', 'f'},
        {'r', 'r', 'w', 's', 'r', 'f', 'f'},
        {'r', 'w', 'w', 's', 'r', 'r', 'r'}};

}


} // namespace Game
