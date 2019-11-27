#include "player.hh"

namespace Game{

Player::Player(const std::string& name):
    Course::PlayerBase(name),
    resources_(BASE_PLAYER_RESOURCE)
{

}

void Player::addNextPlayer(std::shared_ptr<Player> nextP)
{
    next = nextP;
}

const unsigned int Player::getBuildingCount()
{
    return buildings.size();
}

void Player::addBuilding(std::shared_ptr<Course::BuildingBase> &building)
{
    buildings.push_back(building);
}



} // namespace Game
