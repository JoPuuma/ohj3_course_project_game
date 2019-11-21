#include "gameeventhandler.hh"
#include "interfaces/igameeventhandler.h"
#include "core/basicresources.h"
#include<memory>

namespace Game{


GameEventHandler::GameEventHandler(){

}

bool GameEventHandler::modifyResource(
        std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount){

}

bool GameEventHandler::modifyResources(
        std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources){

}

void GameEventHandler::addPlayer(std::string name,
                                 std::shared_ptr<Game::Player> ptr){
    players[name] = ptr;
}

} // namespace Game
