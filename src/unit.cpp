#include "../include/unit.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


const std::map<UnitType, UnitProperties> UnitTypeData::data = {
    { UnitType::K, { 5, 400, 1, 5 } },
    { UnitType::S, { 2, 250, 1, 3 } },
    { UnitType::A, { 2, 250, 5, 3 } },
    { UnitType::P, { 2, 200, 2, 3 } },
    { UnitType::R, { 2, 500, 1, 4 } },
    { UnitType::C, { 2, 800, 7, 6 } },
    { UnitType::W, { 2, 100, 1, 2 } },
    { UnitType::B, { 0, 0, 0, 0 } },
    { UnitType::NONE, { 0, 0, 0, 0 } }
};

const std::map<char, UnitType> CHAR_TO_UNIT_TYPE = {
    {'K', UnitType::K},
    {'S', UnitType::S},
    {'A', UnitType::A},
    {'P', UnitType::P},
    {'C', UnitType::C},
    {'R', UnitType::R},
    {'W', UnitType::W},
    {'B', UnitType::B},
};

const std::map<char, Team> CHAR_TO_TEAM = {
    {'P', Team::PLAYER},
    {'E', Team::ENEMY},
};

const std::map<UnitType, char> UNIT_TYPE_TO_CHAR = {
    {UnitType::K, 'K'},
    {UnitType::S, 'S'},
    {UnitType::A, 'A'},
    {UnitType::P, 'P'},
    {UnitType::C, 'C'},
    {UnitType::R, 'R'},
    {UnitType::W, 'W'},
    {UnitType::B, 'B'},
    {UnitType::NONE, '0'},
};


Unit::Unit(Team team, UnitType type, int id, int x, int y, int durability, UnitType producedUnit)
    : team(team), type(type), id(id), x(x), y(y), durability(durability), producedUnit(producedUnit) {
    try {
        const UnitProperties& props = UnitTypeData::data.at(type);
        speed = props.speed;
        cost = props.cost;
        range = props.range;
        productionTime = props.productionTime;
    } catch (const std::out_of_range& e) {
        std::cerr << "Blad: nie znaleziono wlasnosci dla jednostki " << static_cast<int>(type) << '\n';
    }
}

void Unit::display() const {
    std::string team = (getTeam() == Team::PLAYER) ? "PLAYER" : "ENEMY";
    char producedUnitChar = (getProducedUnit() == UnitType::NONE) ? '0' : UNIT_TYPE_TO_CHAR.at(getProducedUnit());
    std::cout << "Team: " << team << ", Type: " << UNIT_TYPE_TO_CHAR.at(getType()) << ", ID: " << getId() << ", X: " << getX() << ", Y: " << getY()
              << ", Durability: " << getDurability() << ", Produced Unit: " << producedUnitChar << std::endl;
}

// Gettery
Team Unit::getTeam() const { return team; }
UnitType Unit::getType() const { return type; }
int Unit::getId() const { return id; }
int Unit::getX() const { return x; }
int Unit::getY() const { return y; }
int Unit::getDurability() const { return durability; }
UnitType Unit::getProducedUnit() const { return producedUnit; }

// Settery
void Unit::setTeam(Team team) { this->team = team; }
void Unit::setType(UnitType type) { this->type = type; }
void Unit::setId(int id) { this->id = id; }
void Unit::setX(int x) { this->x = x; }
void Unit::setY(int y) { this->y = y; }
void Unit::setDurability(int durability) { this->durability = durability; }
void Unit::setProducedUnit(UnitType producedUnit) { this->producedUnit = producedUnit; }

bool readStatus(const std::string& filename, std::vector<Unit>& units, int& gold) {
    std::ifstream file("data/" + filename);
    int linenumber = 1;

    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku " << "data/" << filename << '\n';
        return false;
    }

    std::string line;

    if (!(file >> gold)) {
        std::cerr << "Blad odczytu liczby zlota z pliku " << filename << '\n';
        return false;
    }

    std::getline(file, line);
    
    while (std::getline(file, line)) {
        linenumber++; // Aktualizujemy numer linii przy każdym wczytaniu nowej linii
        std::istringstream iss(line);

        char teamChar, typeChar, producedUnitChar = '0';
        int id, x, y, durability;

        if (!(iss >> teamChar >> typeChar >> id >> x >> y >> durability)) {
            std::cerr << "Blad odczytu danych z pliku " << filename << " w linii " << linenumber << ": " << line << '\n';
            return false;
        }

        if (iss >> producedUnitChar) {
            // Ostatni parametr jest dostępny
        }

        Team team = CHAR_TO_TEAM.at(teamChar);
        UnitType type = CHAR_TO_UNIT_TYPE.at(typeChar);
        UnitType producedUnit = (producedUnitChar == '0') ? UnitType::NONE : CHAR_TO_UNIT_TYPE.at(producedUnitChar);

        units.push_back(Unit(team, type, id, x, y, durability, producedUnit));
    }

    return true;
}
