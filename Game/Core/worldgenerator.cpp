#include "worldgenerator.hh"

#include "Tiles/rock.hh"
#include "Tiles/sand.hh"
#include "Tiles/water.hh"
#include "tiles/forest.h"

#include "vector"


namespace Game {

WorldGenerator &WorldGenerator::getInstance()
{
    static WorldGenerator instance;
    return instance;
}



template<typename T>
void WorldGenerator::addConstructor(char n)
{
    TileConstructorPointer ctor = std::make_shared<T, Course::Coordinate,
        std::shared_ptr<GameEventHandler>,
        std::shared_ptr<ObjectManager> >;
    m_ctors.insert(std::make_pair(n, ctor));
}



void WorldGenerator::GenerateMap(
        unsigned int size_x,
        unsigned int size_y,
        const std::shared_ptr<ObjectManager>& objectmanager,
        const std::shared_ptr<GameEventHandler>& eventhandler)
{
    GreateReferenceMap();
    std::vector<std::shared_ptr<Course::TileBase>> tiles;

    for (unsigned int x = 0; x < size_x; ++x)
    {
        for (unsigned int y = 0; y < size_y; ++y)
        {
            for (const auto&ctor : m_ctors)
            {
                if (ctor.first == Referencemap[x][y])
                {
                 tiles.push_back(ctor.second(Course::Coordinate(x, y), eventhandler, objectmanager));
                }
            }

        }
    }

    objectmanager->addTiles(tiles);

}


void WorldGenerator::GreateReferenceMap()
{
       Referencemap = {
        {'f', 'r', 's', 'w', 'w', 'f', 'r'},
        {'f', 'r', 's', 'w', 'f', 'f', 'r'},
        {'f', 'f', 's', 'w', 'f', 'f', 'f'},
        {'f', 's', 'w', 'w', 'f', 's', 'f'},
        {'f', 's', 'w', 's', 's', 's', 'f'},
        {'r', 'r', 'w', 's', 'r', 'f', 'f'},
        {'r', 'w', 'w', 's', 'r', 'r', 'r'}};

}


} // namespace Game
