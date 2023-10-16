#include "mage.h"

Mage::Mage(std::string name, Race race)
    : Player(name, race, 200, 0) {}

Mage::~Mage() {}

std::string Mage::attack() const {
    return "I will crush you with my arcane missiles!";
}