#ifndef OBJECTMANAGER_HH
#define OBJECTMANAGER_HH
#include "interfaces/iobjectmanager.h"
#include "Graphics/gamescene.hh"
#include "Core/gameeventhandler.hh"

#include "Buildings/cottage.hh"
#include "Buildings/fishinghut.hh"
#include "Buildings/mine.hh"
#include "buildings/headquarters.h"
#include "Workers/miner.hh"
#include "Workers/fisher.hh"
#include "Workers/timberjack.hh"
#include "objecttypes.hh"

#include<map>
#include<memory>
#include<vector>



namespace Game {

class Player;
class GameEventHandler;

/**
 * @brief The ObjectManager class
 */
class ObjectManager: public Course::iObjectManager
{
public:
    ObjectManager(std::shared_ptr<Game::GameScene> scene);

    /**
     * @brief Adds new tiles to the ObjectManager.
     * @param tiles contains the tiles to be added.
     */
    virtual void addTiles(
            const std::vector<std::shared_ptr<Course::TileBase>>& tiles);

    /**
     * @brief Returns a pointer to a Tile that has specified coordinate.
     * @param coordinate\
                    GameLib
     * @return
     * @post Exception Guarantee: Basic
     */
    virtual std::shared_ptr<Course::TileBase> getTile(
            const Course::Coordinate& coordinate);

    /**
     * @brief Returns a pointer to a Tile that has specified ID
     * @param id
     * @return
     * @post Exception Guarantee: Basic
     */
    virtual std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId& id);

    /**
     * @brief Returns a vector of pointers to Tiles specified by Coordinates.
     * @param coordinates
     * @return
     * @post Exception Guarantee: Basic
     */
    virtual std::vector<std::shared_ptr<Course::TileBase>> getTiles(
            const std::vector<Course::Coordinate>& coordinates);

    /**
     * @brief create a new building to the tile.
     *
     * add building's and tile's ownership to player and add them to
     * player's databases.
     *
     * @param tile shared_ptr to the tile
     * @param player shared_ptr to the player
     * @param objectmanager shared_ptr to the objectManager
     * @param eventhandler shared_ptr to the gameEventhandler
     * @param buildingType value to right building type.
     */
    void createBuilding(std::shared_ptr<Course::TileBase> tile,
                        std::shared_ptr<Game::Player>& player,
                        std::shared_ptr<Game::ObjectManager>& objectmanager,
                        std::shared_ptr<Game::GameEventHandler>& eventhandler,
                        BuildingType buildingType);

    /**
     * @brief checks if the building can be built in the tile
     *
     * @param tile shared_ptr to the tile
     * @param player shared_ptr to the player
     * @return true: can build.
     * False: can't build
     */
    bool canBuild(std::shared_ptr<Course::TileBase> tile,
                  std::shared_ptr<Game::Player>& player);

    /**
     * @brief creates HQ to the tile.
     *
     * add HQ's and tile's ownership to the player and add them to
     * player's databases
     *
     * @param tile shared_ptr to the tile
     * @param player shared_ptr to the player
     * @param objectmanager shared_ptr to the objectManager
     * @param eventhandler shared_ptr to the gameEventhandler
     */
    void createHQ(std::shared_ptr<Course::TileBase> tile,
                  std::shared_ptr<Game::Player>& player,
                  std::shared_ptr<Game::ObjectManager>& objectmanager,
                  std::shared_ptr<Game::GameEventHandler>& eventhandler);

    /**
     * @brief add worker to the tile.
     * and remove it from previous tile (if not first time adding).
     *
     * @param tile shared_ptr to the tile
     * @param player shared_ptr to the player
     * @param workerNumber tells the right worker
     */
    void addWorker(std::shared_ptr<Course::TileBase> tile,
                   std::shared_ptr<Game::Player>& player,
                   int workerNumber);

    /**
     * @brief train basicWorker to miner, fisher or timberjack
     * update new worker to player's worker database
     *
     * @param player shared_ptr to the player
     * @param objectmanager shared_ptr to the objectManager
     * @param eventhandler shared_ptr to the gameEventhandler
     * @param type which kind of worker to train
     * @param workerNumber tells the right worker
     */
    void trainWorker(std::shared_ptr<Game::Player>& player,
                     std::shared_ptr<Game::ObjectManager>& objectmanager,
                     std::shared_ptr<Game::GameEventHandler>& eventhandler,
                     WorkerType& type,
                     int workerNumber);

    /**
     * @brief getTiles
     * @return vector of all tiles
     */
    std::vector<std::shared_ptr<Course::TileBase>> getTiles();


private:
    std::map<std::string, std::shared_ptr<Game::Player>> players;
    std::shared_ptr<Game::GameScene> gameScene = nullptr;
    std::vector<std::shared_ptr<Course::TileBase>> tiles_;

};

}// namespace Game

#endif // OBJECTMANAGER_HH
