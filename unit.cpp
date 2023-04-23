#include "Unit.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Unit::Unit(Team team, UnitType type, int id, int x, int y, int durability, UnitType producedUnit)
    : team(team), type(type), id(id), x(x), y(y), durability(durability), producedUnit(producedUnit) {}

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
    std::ifstream file(filename);
    int linenumber = 1;

    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku " << filename << '\n';
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

        Team team = (teamChar == 'P') ? Team::PLAYER : Team::ENEMY;
        UnitType type = static_cast<UnitType>(typeChar - 'A');
        UnitType producedUnit = (producedUnitChar == '0') ? UnitType::NONE : static_cast<UnitType>(producedUnitChar - 'A');

        units.push_back(Unit(team, type, id, x, y, durability, producedUnit));
    }

    return true;
}