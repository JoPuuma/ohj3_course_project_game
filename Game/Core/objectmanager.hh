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


    void addPlayer(std::string name,std::shared_ptr<Game::Player> ptr);

    void createBuilding(std::shared_ptr<Course::TileBase> tile,
                        std::shared_ptr<Game::Player>& player,
                        std::shared_ptr<Game::ObjectManager>& objectmanager,
                        std::shared_ptr<Game::GameEventHandler>& eventhandler,
                        BuildingType buildingType);

    void createHQ(std::shared_ptr<Course::TileBase> tile,
                  std::shared_ptr<Game::Player>& player,
                  std::shared_ptr<Game::ObjectManager>& objectmanager,
                  std::shared_ptr<Game::GameEventHandler>& eventhandler);

    void addWorker(std::shared_ptr<Course::TileBase> tile,
                   std::shared_ptr<Game::Player>& player,
                   int workerNumber);

    void trainWorker(std::shared_ptr<Game::Player>& player,
                     std::shared_ptr<Game::ObjectManager>& objectmanager,
                     std::shared_ptr<Game::GameEventHandler>& eventhandler,
                     WorkerType& type,
                     int workerNumber);



private:
    std::map<std::string, std::shared_ptr<Game::Player>> players;
    std::shared_ptr<Game::GameScene> gameScene = nullptr;
    std::vector<std::shared_ptr<Course::TileBase>> tiles_;

};

}// namespace Game

#endif // OBJECTMANAGER_HH
