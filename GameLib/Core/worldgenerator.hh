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


class WorldGenerator
{
public:
    WorldGenerator();

    template<typename T>
    void addConstructor(char n);

    void GenerateMap(unsigned int size_x,
                     unsigned int size_y,
                     const std::shared_ptr<ObjectManager>& ObjectManager,
                     const std::shared_ptr<GameEventHandler>& EventHandler);


    void GreateReferenceMap();

private:
    std::vector<std::vector<char>> Referencemap = {};

    std::map<char, TileConstructorPointer> m_ctors;

}; // class WorldGenerator

} // namespace Game

#endif // WORLDGENERATOR_HH
