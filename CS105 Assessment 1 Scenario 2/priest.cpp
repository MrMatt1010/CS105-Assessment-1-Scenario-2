#include "priest.h"

Priest::Priest(std::string name, Race race)
    : Player(name, race, 200, 0) {}

Priest::~Priest() {}

std::string Priest::attack() const {
    return "I will assault you with holy wrath!";
}