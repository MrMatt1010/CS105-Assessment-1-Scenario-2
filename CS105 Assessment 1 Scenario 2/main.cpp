// CS105 - RPG-Game-Scenario2.cpp
// Matt Taylor 

// main.cpp
#include <iostream>
#include <vector>
#include "player.h"
#include "warrior.h"
#include "priest.h"
#include "mage.h"

int main() {
    std::vector<Warrior> warriors;
    std::vector<Priest> priests;
    std::vector<Mage> mages;

    while (true) {
        std::cout << "Choose a class for your player:" << std::endl;
        std::cout << "1. Warrior" << std::endl;
        std::cout << "2. Priest" << std::endl;
        std::cout << "3. Mage" << std::endl;
        std::cout << "4. Exit" << std::endl;
        int choice;
        std::cin >> choice;

        if (choice == 4) {
            break;
        }

        std::string name;
        std::cout << "Enter player name: ";
        std::cin >> name;

        Race race;
        int raceChoice;
        std::cout << "Choose a race for your player:" << std::endl;
        std::cout << "1. HUMAN" << std::endl;
        std::cout << "2. ELF" << std::endl;
        std::cout << "3. DWARF" << std::endl;
        std::cout << "4. ORC" << std::endl;
        std::cout << "5. TROLL" << std::endl;
        std::cin >> raceChoice;
        switch (raceChoice) {
        case 1: race = HUMAN; break;
        case 2: race = ELF; break;
        case 3: race = DWARF; break;
        case 4: race = ORC; break;
        case 5: race = TROLL; break;
        default: race = HUMAN; break;
        }

        switch (choice) {
        case 1:
            warriors.emplace_back(name, race);
            break;
        case 2:
            priests.emplace_back(name, race);
            break;
        case 3:
            mages.emplace_back(name, race);
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    // Print player details and attack methods
    for (const Warrior& warrior : warriors) {
        std::cout << "Name: " << warrior.getName() << ", Race: " << warrior.getRace() << ", HP: "
            << warrior.getHitPoints() << ", MP: " << warrior.getMagicPoints()
            << ", Attack: " << warrior.attack() << std::endl;
    }

    for (const Priest& priest : priests) {
        std::cout << "Name: " << priest.getName() << ", Race: " << priest.getRace() << ", HP: "
            << priest.getHitPoints() << ", MP: " << priest.getMagicPoints()
            << ", Attack: " << priest.attack() << std::endl;
    }

    for (const Mage& mage : mages) {
        std::cout << "Name: " << mage.getName() << ", Race: " << mage.getRace() << ", HP: "
            << mage.getHitPoints() << ", MP: " << mage.getMagicPoints()
            << ", Attack: " << mage.attack() << std::endl;
    }

    return 0;
}