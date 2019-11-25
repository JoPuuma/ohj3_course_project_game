#ifndef OBJECTMANAGER_HH
#define OBJECTMANAGER_HH
#include "interfaces/iobjectmanager.h"
#include "Graphics/gamescene.hh"
#include "Core/gameeventhandler.hh"

#include "Buildings/cottage.hh"
#include "Buildings/fishinghut.hh"
#include "Buildings/mine.hh"
#include<map>
#include<memory>
#include<vector>



namespace Game {

class Player;


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
    void createBuilding(std::shared_ptr<Course::GameObject> tile,
                        std::shared_ptr<Game::Player> player,
                        std::shared_ptr<Game::ObjectManager>& objectmanager,
                        std::shared_ptr<Game::GameEventHandler>& eventhandler,
                        std::string buildingType);

private:
    std::map<std::string, std::shared_ptr<Game::Player>> players;
    std::shared_ptr<Game::GameScene> gameScene = nullptr;
    std::vector<std::shared_ptr<Course::TileBase>> tiles_;

};

}// namespace Game

#endif // OBJECTMANAGER_HH
