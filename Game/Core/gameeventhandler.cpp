#include "gameeventhandler.hh"
#include "interfaces/igameeventhandler.h"
#include "core/basicresources.h"
#include "Core/player.hh"
#include "Workers/basicworker.hh"

#include<memory>

namespace Game{

const int MAX_ROUND_OFF = -1;

GameEventHandler::GameEventHandler():
    players({}),
    round_(1),
    maxRound_(MAX_ROUND_OFF)
{

}

bool GameEventHandler::modifyResource(
        std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{

}

bool GameEventHandler::modifyResources(
        std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    std::shared_ptr<Game::Player> p = std::dynamic_pointer_cast<Game::Player>(player);
    Course::ResourceMap newResources = Course::mergeResourceMaps(p->resources_, resources);
    for(const auto& resource : newResources){
        if(resource.second < 0 ) return false;
    }
    p->resources_ = newResources;
    return true;
}

void GameEventHandler::addPlayer(std::string name,
                                 std::shared_ptr<Game::Player> ptr){
    players[name] = ptr;
}

void GameEventHandler::addBasicWorkers(std::shared_ptr<Game::GameEventHandler>& eventhandler,
                                       std::shared_ptr<Game::ObjectManager>& objectmanager)
{
    for (const auto& player : playerPtrs) {

        for (unsigned int i = 1; i < 6; ++i) {

            player->workers[i] = std::make_shared<Game::basicWorker>(eventhandler,
                                                                       objectmanager,
                                                                       player);
        }
    }
}

void GameEventHandler::initializeGame(const std::vector<std::string>& players,
                                      std::shared_ptr<Game::GameEventHandler>& eventhandler,
                                      std::shared_ptr<Game::ObjectManager>& objectmanager,
                                      const int& rounds)
{
    // create players
    std::shared_ptr<Game::Player> previousPlayerPtr = nullptr;
    for(const std::string &player : players){
        // new player
        std::shared_ptr<Game::Player> ptr =
                    std::make_shared<Game::Player>(Game::Player(player));                   

        addPlayer(player,ptr); // TARPEELLINEN?
        playerPtrs.push_back(ptr);

        if(previousPlayerPtr != nullptr){
            previousPlayerPtr->addNextPlayer(ptr);
        }
        previousPlayerPtr = ptr;
    }
    eInTurn = playerPtrs[0];
    addBasicWorkers(eventhandler,objectmanager);

    if(rounds != MAX_ROUND_OFF) maxRound_ = rounds;
}

std::shared_ptr<Player> GameEventHandler::currentPlayer()
{
    return eInTurn;
}

unsigned int GameEventHandler::getRound()
{
    return round_;
}

void GameEventHandler::endTurn()
{
    if(eInTurn->next == nullptr){
        eInTurn = playerPtrs[0];
        round_++;
    }else{
        eInTurn = eInTurn->next;
    }
}

bool GameEventHandler::gameEnd()
{
    if(maxRound_ == MAX_ROUND_OFF){
        return true; // all tiles in use
    }
    else return round_ >= maxRound_;
}

} // namespace Game
