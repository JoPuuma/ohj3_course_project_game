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

int Player::getBuildingCount()
{
    return buildings.size();
}

void Player::addTile(std::shared_ptr<Course::TileBase>& tile)
{
    tiles.push_back(tile);
}

std::vector<std::shared_ptr<Course::TileBase>> Player::getTiles()
{
    return tiles;
}

void Player::updateResources()
{
    for (auto& tile : tiles) {
        tile->generateResources();
    }
}

void Player::addBuilding(std::shared_ptr<Course::BuildingBase> &building)
{
    buildings.push_back(building);
}



} // namespace Game
