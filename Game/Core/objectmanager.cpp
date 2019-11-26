#include "objectmanager.hh"

#include "gamewindow.hh"
#include "graphics/simplegamescene.h"
#include "Core/player.hh"


namespace Game {


ObjectManager::ObjectManager(std::shared_ptr<Game::GameScene> scene):
    Course::iObjectManager(),
    gameScene(scene)
{

}

void ObjectManager::addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles)
{
    tiles_ = tiles;
    for (auto tile : tiles) {
        gameScene->DrawItem(tile);
    }
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::ObjectId &id)
{
    for(auto& tile : tiles_){
        if(tile->ID == id){
            return tile;
        }
    }
}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles(const std::vector<Course::Coordinate> &coordinates)
{

}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate)
{

}

void ObjectManager::addPlayer(std::string name, std::shared_ptr<Game::Player> ptr){
    players[name] = ptr;
}

void ObjectManager::createBuilding(std::shared_ptr<Course::GameObject> tile,
                                   std::shared_ptr<Player>& player,
                                   std::shared_ptr<ObjectManager> &objectmanager,
                                   std::shared_ptr<GameEventHandler> &eventhandler,
                                   std::string buildingType)
{
    std::shared_ptr<Course::BuildingBase> buildingPtr = nullptr;

    if (buildingType == "Cottage") {

        buildingPtr = std::make_shared<Game::Cottage>(eventhandler,
                                                      objectmanager,
                                                      player);
    }
    else if (buildingType == "FishingHut") {
        buildingPtr = std::make_shared<Game::Fishinghut>(eventhandler,
                                                         objectmanager,
                                                         player);

    }
    else if (buildingType == "Mine") {
        buildingPtr = std::make_shared<Game::Mine>(eventhandler,
                                                   objectmanager,
                                                   player);

    }
    else if (buildingType == "HQ") {
        buildingPtr = std::make_shared<Course::HeadQuarters>(eventhandler,
                                                 objectmanager,
                                                 player);

    }

    if (eventhandler->modifyResources(player,buildingPtr->BUILD_COST)) {

         std::dynamic_pointer_cast<Course::TileBase>(tile)->addBuilding(buildingPtr);
    }

}



void ObjectManager::addWorker(std::shared_ptr<Course::GameObject> tile,
                              std::shared_ptr<Player> player,
                              std::shared_ptr<ObjectManager> &objectmanager,
                              std::shared_ptr<GameEventHandler> &eventhandler,
                              std::string WorkerType)
{


}

}//namespace
