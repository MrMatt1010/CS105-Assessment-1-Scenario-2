#pragma once

#include <iostream>

enum Race { HUMAN, ELF, DWARF, ORC, TROLL };

class Player {
private:
    std::string name;
    Race race;
    int hitPoints;
    int magicPoints;

public:
    Player(std::string name, Race race, int hitPoints, int magicPoints);
    virtual ~Player();

    // Getters and setters
    std::string getName() const;
    Race getRace() const;
    int getHitPoints() const;
    int getMagicPoints() const;
    void setName(std::string name);
    void setRace(Race race);
    void setHitPoints(int hitPoints);
    void setMagicPoints(int magicPoints);

    // Virtual attack function
    virtual std::string attack() const;
};