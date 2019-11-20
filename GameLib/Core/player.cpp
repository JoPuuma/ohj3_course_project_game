#include "player.hh"

namespace Game{

Player::Player(const std::string& name):
    Course::PlayerBase(name),
    name_(name){

}

} // namespace Game
