#include "player.hh"

namespace Game{

Player::Player(const std::string& name):
    Course::PlayerBase(name),
    resources_(BASE_PLAYER_RESOURCE){

}


} // namespace Game
