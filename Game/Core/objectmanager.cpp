#include "objectmanager.hh"
#include "gamewindow.hh"
#include "Core/player.hh"
#include "Core/resourcemaps.hh"
#include "core/coordinate.h"
#include "exceptions/illegalaction.h"

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
    return nullptr;
}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles(const std::vector<Course::Coordinate> &coordinates)
{
    Q_UNUSED(coordinates);
    std::vector<std::shared_ptr<Course::TileBase> >v;
    return v;
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate)
{
    Q_UNUSED(coordinate);
    return nullptr;
}

void ObjectManager::createBuilding(std::shared_ptr<Course::TileBase> tile,
                                   std::shared_ptr<Game::Player>& player,
                                   std::shared_ptr<Game::ObjectManager>& objectmanager,
                                   std::shared_ptr<Game::GameEventHandler>& eventhandler,
                                   BuildingType buildingType)
{
    if ( canBuild(tile,player)) {

        std::shared_ptr<Course::BuildingBase> buildingPtr = nullptr;
        bool suitableTile = false;

        if (buildingType == COTTAGE && tile->getType() != "Water") {

            buildingPtr = std::make_shared<Game::Cottage>(eventhandler,
                                                          objectmanager,
                                                          player);
            suitableTile = true;
        }
        else if (buildingType == FISHINGHUT && tile->getType() == "Water") {

            buildingPtr = std::make_shared<Game::Fishinghut>(eventhandler,
                                                             objectmanager,
                                                             player);
            suitableTile = true;

        }
        else if (buildingType == MINE && tile->getType() == "Rock") {

            buildingPtr = std::make_shared<Game::Mine>(eventhandler,
                                                       objectmanager,
                                                       player);
            suitableTile = true;

        }

        if (suitableTile) {
            try {
                 tile->addBuilding(buildingPtr);

                 // player needs to have resources to make building.
                 if (eventhandler->modifyResources(player,buildingPtr->BUILD_COST)) {

                     tile->setOwner(player);
                     buildingPtr->setOwner(player);
                     player->addBuilding(buildingPtr);
                     player->addTile(tile);
                     gameScene->drawBuilding(buildingPtr);
                     gameScene->addPen(tile,player->getColor());
                     eventhandler->maxMoves += 1;

                   }
                 else {
                     tile->removeBuilding(buildingPtr);
                 }
            }
            catch(std::exception& e) {

                qDebug() << "can't add building";
            }

        }
    }
}

bool ObjectManager::canBuild(std::shared_ptr<Course::TileBase> tile,
                             std::shared_ptr<Game::Player>& player)
{
    if (tile->getOwner() == player || tile->getOwner() == nullptr) {

        std::vector<Course::Coordinate> neighbourVector;
        std::vector<std::shared_ptr<Course::TileBase>> playerTiles;

        neighbourVector =  tile->getCoordinate().neighbours(1);
        playerTiles = player->getTiles();
        for (auto neighbour : neighbourVector) {

            for (auto tile : playerTiles) {

                // player needs to own atleast one tile around new tile.
                if (tile->getCoordinate().x() == neighbour.x() &&
                    tile->getCoordinate().y() == neighbour.y()) {

                    return true;
                }
            }
        }
        return false;
    }
    return false;
}


void ObjectManager::createHQ(std::shared_ptr<Course::TileBase> tile,
                             std::shared_ptr<Game::Player>& player,
                             std::shared_ptr<Game::ObjectManager>& objectmanager,
                             std::shared_ptr<Game::GameEventHandler>& eventhandler)
{

    std::shared_ptr<Course::BuildingBase> buildinPtr = nullptr;
    bool suitableTile = false;

        if (tile->getType() != "Water") {

             buildinPtr = std::make_shared<Course::HeadQuarters>(eventhandler,
                                                                 objectmanager,
                                                                 player);
            suitableTile = true;
    }

    if (suitableTile) {

        try {
            tile->addBuilding(buildinPtr);
            tile->setOwner(player);
            buildinPtr->setOwner(player);
            player->addBuilding(buildinPtr);
            player->addTile(tile);

            gameScene->currentObject = nullptr;
            gameScene->drawBuilding(buildinPtr);
            gameScene->addPen(tile,player->getColor());

         }
        catch(std::exception& e) {

            qDebug() << "can't place HQ";

        }
    }

}

void ObjectManager::addWorker(std::shared_ptr<Course::TileBase> tile,
                              std::shared_ptr<Game::Player>& player,
                              int workerNumber)
{
    std::shared_ptr<Course::TileBase> previousTile =
                player->workers[workerNumber]->currentLocationTile();

    // can't add worker to same tile multiple times.
    if (previousTile != tile) {

        try {

            if (previousTile != nullptr) {
                previousTile->removeWorker(player->workers[workerNumber]);
            }

            tile->addWorker(player->workers[workerNumber]);
            gameScene->drawWorker(player->workers[workerNumber], workerNumber);

            }
            catch(std::exception& e){

                qDebug() << "can't add worker";
            }
    }
}

void ObjectManager::trainWorker(std::shared_ptr<Game::Player>& player,
                                std::shared_ptr<Game::ObjectManager>& objectmanager,
                                std::shared_ptr<Game::GameEventHandler>& eventhandler,
                                WorkerType& type,
                                int workerNumber)
    {

     unsigned int oldID = player->workers[workerNumber]->ID;

    std::shared_ptr<Course::TileBase> Tile =
                  player->workers[workerNumber]->currentLocationTile();

    if (type == MINER &&
        player->workers[workerNumber]->getType() == "basicWorker" &&
        eventhandler->modifyResources(player,ConstResourceMap::MINER_RECRUITMENT_COST)) {

        // remove basicWorker from the tile
        if (Tile != nullptr) {
          Tile->removeWorker(player->workers[workerNumber]);
        }
          player->workers[workerNumber] = std::make_shared<Game::Miner>(eventhandler,
                                                                        objectmanager,
                                                                        player);
          // add new worker to the tile
          if (Tile != nullptr) {
          Tile->addWorker( player->workers[workerNumber]);
          }
          gameScene->UpdateItem(player->workers[workerNumber], oldID);
          eventhandler->maxMoves += 1;
    }
    else if (type == FISHER &&
             player->workers[workerNumber]->getType() == "basicWorker" &&
             eventhandler->modifyResources(player,ConstResourceMap::FISHER_RECRUITMENT_COST)) {

        if (Tile != nullptr) {
          Tile->removeWorker(player->workers[workerNumber]);
        }
        player->workers[workerNumber] = std::make_shared<Game::Fisher>(eventhandler,
                                                                       objectmanager,
                                                                       player);
        if (Tile != nullptr) {
        Tile->addWorker( player->workers[workerNumber]);
        }
        gameScene->UpdateItem(player->workers[workerNumber], oldID);
        eventhandler->maxMoves += 1;
    }
    else if (type == TIMBERJACK &&
             player->workers[workerNumber]->getType() == "basicWorker" &&
             eventhandler->modifyResources(player,ConstResourceMap::TIMBERJACK_RECRUITMENT_COST)) {

        if (Tile != nullptr) {
          Tile->removeWorker(player->workers[workerNumber]);
        }
        player->workers[workerNumber] = std::make_shared<Game::Timberjack>(eventhandler,
                                                                           objectmanager,
                                                                         player);
        if (Tile != nullptr) {
        Tile->addWorker( player->workers[workerNumber]);
        }
        gameScene->UpdateItem(player->workers[workerNumber], oldID);
        eventhandler->maxMoves += 1;
    }


}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles()
{
    return tiles_;
}

}//namespace
