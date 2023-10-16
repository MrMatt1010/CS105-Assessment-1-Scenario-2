
#include "player.h"

class Warrior : public Player {
public:
    Warrior(std::string name, Race race);
    ~Warrior();
    std::string attack() const override;
};