// Scenario 2
// Student Name: Matt Taylor
// This is a program that creates three character players as outlined in the brief

#include <iostream>
#include <vector>

enum Race { HUMAN, ELF, DWARF, ORC, TROLL };
//This function converts the enum values to corresponding string reperesentations
std::string raceToString(Race race) {
    switch (race) {
    case HUMAN:
        return "HUMAN";
    case ELF:
        return "ELF";
    case DWARF:
        return "DWARF";
    case ORC:
        return "ORC";
    case TROLL:
        return "TROLL";
    default:
        return "UNKNOWN";
    }
};

//This is the base class, There are two virtual functions here for the derived classes to overwrite when needed. 
class Player {
private:
    std::string name;
    Race race;
    int hitPoints;
    int magicPoints;

public:
    Player(std::string name, Race race, int hitPoints, int magicPoints)
        : name(name), race(race), hitPoints(hitPoints), magicPoints(magicPoints) {}

    std::string getName() const {
        return name;
    }

    Race getRace() const {
        return race;
    }

    int getHitPoints() const {
        return hitPoints;
    }

    int getMagicPoints() const {
        return magicPoints;
    }

    void setName(std::string name) {
        this->name = name;
    }

    void setRace(Race race) {
        this->race = race;
    }

    void setHitPoints(int hitPoints) {
        this->hitPoints = hitPoints;
    }

    void setMagicPoints(int magicPoints) {
        this->magicPoints = magicPoints;
    }

    virtual std::string attack() const {
        return "No attack method defined yet!";
    }

    virtual std::string getClass() const {
        return "Player";
    }
};
//below are the derived classes. 
class Warrior : public Player {
public:
    Warrior(std::string name, Race race)
        : Player(name, race, 200, 0) {}

    std::string attack() const override {
        return "I will destroy you with my sword, foul demon!";
    }

    std::string getClass() const override {
        return "Warrior";
    }

};

class Priest : public Player {
public:
    Priest(std::string name, Race race)
        : Player(name, race, 100, 200) {}

    std::string attack() const override {
        return "I will assault you with holy wrath!";
    }

    std::string getClass() const override {
        return "Priest";
    }
};

class Mage : public Player {
public:
    Mage(std::string name, Race race)
        : Player(name, race, 200, 0) {}

    std::string attack() const override {
        return "I will crush you with my arcane missiles!";
    }

    std::string getClass() const override {
        return "Mage";
    }
};

int main() {

std::cout << "******Character Creation******\n";
std::cout << "" << std::endl;

    std::vector<Player*> players;
    const int maxPlayers = 3; // Allows the creation of three characters
// This is the loop for creating the characters. 
    for (int i = 0; i < maxPlayers; ++i) {
        std::cout << "Create character " << (i + 1) << ":" << std::endl;

        std::string name;
        std::cout << "What would you like to name your character?: ";
        std::cin >> name;

        Race race;
        int raceChoice;
        std::cout << "What race do you want?: " << std::endl;
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

        int classChoice;
        std::cout << "Choose a class for your character: " << std::endl;
        std::cout << "1. Create a Warrior" << std::endl;
        std::cout << "2. Create a Priest" << std::endl;
        std::cout << "3. Create a Mage" << std::endl;
        std::cin >> classChoice;

        Player* player = nullptr;

        switch (classChoice) {
        case 1:
            player = new Warrior(name, race);
            break;
        case 2:
            player = new Priest(name, race);
            break;
        case 3:
            player = new Mage(name, race);
            break;
        default:
            std::cout << "Invalid choice. Exiting." << std::endl;
            return 0;
        }

        players.push_back(player);

    }

// Prints player details, including class and race
    for (Player* player : players) {
        std::cout << "My name is " << player->getName() << ", I am a  " << raceToString(player->getRace()) << ", I am a  "
            << player->getClass() << ", and my attack is " << player->attack() << std::endl;
        delete player; // Deallocate memory for each player
    }


    return 0;
}
