#ifndef PLAYER_HH
#define PLAYER_HH

#include "core/playerbase.h"
#include "core/basicresources.h"
#include "workers/workerbase.h"
#include "buildings/buildingbase.h"
#include "tiles/tilebase.h"

#include <map>

namespace Game{

const Course::ResourceMap BASE_PLAYER_RESOURCE = {
    {Course::BasicResource::NONE, 0},
    {Course::BasicResource::MONEY, 1000},
    {Course::BasicResource::FOOD, 600},
    {Course::BasicResource::WOOD, 400},
    {Course::BasicResource::STONE, 400},
    {Course::BasicResource::ORE, 100}
};

/**
 * @brief The Player class represents Player in the game.
 */
class Player: public Course::PlayerBase
{
public:

    /**
     * @brief Constructor of the class.
     * @param name player's name.
     * @param color player's color to mark own tiles.
     */
    Player(const std::string& name, const int& color);

    /**
     * @brief addNextPlayer
     * @param nextP pointer to next player
     */
    void addNextPlayer(std::shared_ptr<Game::Player> nextP);

    /**
     * @brief add new building to the player.
     * @param building shared ptr to the building.
     */
    void addBuilding(std::shared_ptr<Course::BuildingBase>& building);

    /**
     * @brief getBuildingCount
     * @return number of buildings.
     */
    int getBuildingCount();

    /**
     * @brief getColor
     * @return player's own color.
     */
    int getColor();

    /**
     * @brief add new tile to the player.
     * @param tile shared ptr to the tile.
     */
    void addTile(std::shared_ptr<Course::TileBase>& tile);

    /**
     * @brief getTiles
     * @return vector of player's own tiles.
     */
    std::vector<std::shared_ptr<Course::TileBase>> getTiles();

    /**
     * @brief update resources from player's own tiles.
     */
    void updateResources();

    Course::ResourceMap resources_;
    std::shared_ptr<Game::Player> next = nullptr;
    std::map<int,std::shared_ptr<Course::WorkerBase>> workers;

private:  
    std::vector<std::shared_ptr<Course::BuildingBase>> buildings;
    std::vector<std::shared_ptr<Course::TileBase>> tiles;
    int color_;
};

} // namespace Game

#endif // PLAYER_HH
