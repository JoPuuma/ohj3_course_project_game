#include "fishinghut.hh"


namespace Game {

Fishinghut::Fishinghut(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                       const std::shared_ptr<Course::iObjectManager>& objectmanager,
                       const std::shared_ptr<Course::PlayerBase>& owner,
                       const int& tilespaces,
                       const Course::ResourceMap& buildcost,
                       const Course::ResourceMap& production
                       ):
                BuildingBase(
                    eventhandler,
                    objectmanager,
                    owner,
                    tilespaces,
                    buildcost,
                    production)

{
}

std::string Fishinghut::getType() const
{
    return  "Fishinghut";
}

} // namespace Game

