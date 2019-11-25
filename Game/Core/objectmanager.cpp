#include "objectmanager.hh"

#include "gamewindow.hh"
#include "graphics/simplegamescene.h"



namespace Game {


ObjectManager::ObjectManager(std::shared_ptr<Game::GameScene> scene):
    Course::iObjectManager(),
    gameScene(scene)
{

}

void ObjectManager::addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles)
{

    for (auto tile : tiles) {

        gameScene->DrawItem(tile);
    }
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::ObjectId &id)
{

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

}//namespace
