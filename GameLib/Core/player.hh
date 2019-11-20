#ifndef PLAYER_HH
#define PLAYER_HH

#include "core/playerbase.h"

namespace Game{

class Player: public Course::PlayerBase
{
public:
    Player(const std::string& name);

private:
    std::string name_;
};

} // namespace Game

#endif // PLAYER_HH
