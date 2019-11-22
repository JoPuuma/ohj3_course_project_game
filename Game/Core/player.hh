#ifndef PLAYER_HH
#define PLAYER_HH

#include "core/playerbase.h"
#include "core/basicresources.h"

namespace Game{

const Course::ResourceMap BASE_PLAYER_RESOURCE = {
    {Course::BasicResource::NONE, 0},
    {Course::BasicResource::MONEY, 100},
    {Course::BasicResource::FOOD, 80},
    {Course::BasicResource::WOOD, 50},
    {Course::BasicResource::STONE, 50},
    {Course::BasicResource::ORE, 10}
};

class Player: public Course::PlayerBase
{
public:
    Player(const std::string& name);

    void addNextPlayer(std::shared_ptr<Game::Player> nextP);

    Course::ResourceMap resources_;
    std::shared_ptr<Game::Player> next = nullptr;

private:

};

} // namespace Game

#endif // PLAYER_HH
