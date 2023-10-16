#include "player.h"

Player::Player(std::string name, Race race, int hitPoints, int magicPoints)
    : name(name), race(race), hitPoints(hitPoints), magicPoints(magicPoints) {}

Player::~Player() {}

std::string Player::getName() const {
    return name;
}

Race Player::getRace() const {
    return race;
}

int Player::getHitPoints() const {
    return hitPoints;
}

int Player::getMagicPoints() const {
    return magicPoints;
}

void Player::setName(std::string name) {
    this->name = name;
}

void Player::setRace(Race race) {
    this->race = race;
}

void Player::setHitPoints(int hitPoints) {
    this->hitPoints = hitPoints;
}

void Player::setMagicPoints(int magicPoints) {
    this->magicPoints = magicPoints;
}

std::string Player::attack() const {
    return "No attack method defined yet!";
}