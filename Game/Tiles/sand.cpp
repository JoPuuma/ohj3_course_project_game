#include "sand.hh"

namespace Game {

Sand::Sand(const Course::Coordinate& location,
           const std::shared_ptr<Game::GameEventHandler>& eventhandler,
           const std::shared_ptr<Game::ObjectManager>& objectmanager,
           const unsigned int& max_build,
           const unsigned int& max_work,
           const Course::ResourceMap& production):
            TileBase(location,
                     eventhandler,
                     objectmanager,
                     max_build,
                     max_work,
                     production)
{
}
std::string Sand::getType() const
{
    return "Sand";
}

void Sand::addBuilding(const std::shared_ptr<Course::BuildingBase> &building)
{
    TileBase::addBuilding(building);
    building->addHoldMarkers(1);
}

} //namescape Game

