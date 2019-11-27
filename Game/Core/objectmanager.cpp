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
                                   std::shared_ptr<Game::Player>& player,
                                   std::shared_ptr<Game::ObjectManager>& objectmanager,
                                   std::shared_ptr<Game::GameEventHandler>& eventhandler,
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

    if (eventhandler->modifyResources(player,buildingPtr->BUILD_COST)) {

         std::dynamic_pointer_cast<Course::TileBase>(tile)->addBuilding(buildingPtr);
         tile->setOwner(player);
         buildingPtr->setOwner(player);
         player->addBuilding(buildingPtr);

    }

}


void ObjectManager::createHQ(std::shared_ptr<Course::GameObject> tile,
                             std::shared_ptr<Game::Player>& player,
                             std::shared_ptr<Game::ObjectManager>& objectmanager,
                             std::shared_ptr<Game::GameEventHandler>& eventhandler)
{
    std::shared_ptr<Course::BuildingBase> buildinPtr =
                                        std::make_shared<Course::HeadQuarters>(eventhandler,
                                                                               objectmanager,
                                                                                 player);
    std::dynamic_pointer_cast<Course::TileBase>(tile)->addBuilding(buildinPtr);
    tile->setOwner(player);
    buildinPtr->setOwner(player);
    player->addBuilding(buildinPtr);
    gameScene->currentObject = nullptr;

}



void ObjectManager::addWorker(std::shared_ptr<Course::GameObject> tile,
                              std::shared_ptr<Course::WorkerBase>& worker)
{
    std::dynamic_pointer_cast<Course::TileBase>(tile)->addWorker(worker);
}

void ObjectManager::trainWorker(std::shared_ptr<Player>& player,
                                std::shared_ptr<Course::WorkerBase>& worker)
{

}

}//namespace
