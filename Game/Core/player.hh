#ifndef PLAYER_HH
#define PLAYER_HH

#include "core/playerbase.h"
#include "core/basicresources.h"
#include "workers/workerbase.h"

#include <map>

namespace Game{

const Course::ResourceMap BASE_PLAYER_RESOURCE = {
    {Course::BasicResource::NONE, 0},
    {Course::BasicResource::MONEY, 2000},
    {Course::BasicResource::FOOD, 800},
    {Course::BasicResource::WOOD, 500},
    {Course::BasicResource::STONE, 500},
    {Course::BasicResource::ORE, 100}
};

class Player: public Course::PlayerBase
{
public:
    Player(const std::string& name);

    void addNextPlayer(std::shared_ptr<Game::Player> nextP);

    Course::ResourceMap resources_;
    std::shared_ptr<Game::Player> next = nullptr;
    std::map<int,std::shared_ptr<Course::WorkerBase>> workers;

private:

};

} // namespace Game

#endif // PLAYER_HH
