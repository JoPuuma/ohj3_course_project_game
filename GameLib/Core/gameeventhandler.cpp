#include "gameeventhandler.hh"
#include "interfaces/igameeventhandler.h"
#include "core/basicresources.h"
#include<memory>

namespace Game{


GameEventHandler::GameEventHandler():Course::iGameEventHandler(){

}

bool GameEventHandler::modifyResource(
        std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount){

}

bool GameEventHandler::modifyResources(
        std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources){

}

void GameEventHandler::addPlayer(std::string name){
   std::shared_ptr<Game::Player> ptr(new Game::Player(name)); // puuttuu resurssit
    players[name] = ptr;
}

} // namespace Game
