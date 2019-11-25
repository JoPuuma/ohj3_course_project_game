#include "gameeventhandler.hh"
#include "interfaces/igameeventhandler.h"
#include "core/basicresources.h"
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

}

void GameEventHandler::addPlayer(std::string name,
                                 std::shared_ptr<Game::Player> ptr){
    players[name] = ptr;
}

void GameEventHandler::initializeGame(const std::vector<std::string>& players,
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
