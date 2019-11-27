#include "objectmanager.hh"
#include "gamewindow.hh"
#include "graphics/simplegamescene.h"
#include "Core/player.hh"
#include "Core/resourcemaps.hh"


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

void ObjectManager::createBuilding(std::shared_ptr<Course::TileBase> tile,
                                   std::shared_ptr<Game::Player>& player,
                                   std::shared_ptr<Game::ObjectManager>& objectmanager,
                                   std::shared_ptr<Game::GameEventHandler>& eventhandler,
                                   BuildingType buildingType)
{
    std::shared_ptr<Course::BuildingBase> buildingPtr = nullptr;

    if (buildingType == COTTAGE) {

        buildingPtr = std::make_shared<Game::Cottage>(eventhandler,
                                                      objectmanager,
                                                      player);
    }
    else if (buildingType == FISHINGHUT) {
        buildingPtr = std::make_shared<Game::Fishinghut>(eventhandler,
                                                         objectmanager,
                                                         player);

    }
    else if (buildingType == MINE) {
        buildingPtr = std::make_shared<Game::Mine>(eventhandler,
                                                   objectmanager,
                                                   player);

    }
    //if(buildingPtr->canBePlacedOnTile())
    if (eventhandler->modifyResources(player,buildingPtr->BUILD_COST)) {

         tile->addBuilding(buildingPtr);
         tile->setOwner(player);
         buildingPtr->setOwner(player);
         player->addBuilding(buildingPtr);
         player->addTile(tile);

    }

}


void ObjectManager::createHQ(std::shared_ptr<Course::TileBase> tile,
                             std::shared_ptr<Game::Player>& player,
                             std::shared_ptr<Game::ObjectManager>& objectmanager,
                             std::shared_ptr<Game::GameEventHandler>& eventhandler)
{
    std::shared_ptr<Course::BuildingBase> buildinPtr =
                                        std::make_shared<Course::HeadQuarters>(eventhandler,
                                                                               objectmanager,
                                                                                 player);
    tile->addBuilding(buildinPtr);
    tile->setOwner(player);
    buildinPtr->setOwner(player);
    player->addBuilding(buildinPtr);
    player->addTile(tile);
    gameScene->currentObject = nullptr;

}



void ObjectManager::addWorker(std::shared_ptr<Course::TileBase> tile,
                              std::shared_ptr<Game::Player>& player,
                              int workerNumber)
{
    tile->addWorker(player->workers[workerNumber]);
}

void ObjectManager::trainWorker(std::shared_ptr<Game::Player>& player,
                                std::shared_ptr<Game::ObjectManager>& objectmanager,
                                std::shared_ptr<Game::GameEventHandler>& eventhandler,
                                WorkerType& type,
                                int workerNumber)
    {
    if (type == MINER &&
        player->workers[workerNumber]->getType() == "basicWorker" &&
        eventhandler->modifyResources(player,ConstResourceMap::MINER_RECRUITMENT_COST)) {

      player->workers[workerNumber] = std::make_shared<Game::Miner>(eventhandler,
                                                                    objectmanager,
                                                                    player);
    }
    else if (type == FISHER &&
             player->workers[workerNumber]->getType() == "basicWorker" &&
             eventhandler->modifyResources(player,ConstResourceMap::FISHER_RECRUITMENT_COST)) {

        player->workers[workerNumber] = std::make_shared<Game::Fisher>(eventhandler,
                                                                       objectmanager,
                                                                       player);
    }
    else if (type == TIMBERJACK &&
             player->workers[workerNumber]->getType() == "basicWorker" &&
             eventhandler->modifyResources(player,ConstResourceMap::TIMBERJACK_RECRUITMENT_COST)) {

        player->workers[workerNumber] = std::make_shared<Game::Timberjack>(eventhandler,
                                                                           objectmanager,
                                                                           player);
    }


}

}//namespace
