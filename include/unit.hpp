#pragma once

#include <string>
#include <vector>

enum class Team { PLAYER, ENEMY };
enum class UnitType { K, S, A, P, C, R, W, B, NONE };

class Unit {
public:
    Unit(Team team, UnitType type, int id, int x, int y, int durability, UnitType producedUnit = UnitType::NONE);

    // Gettery
    Team getTeam() const;
    UnitType getType() const;
    int getId() const;
    int getX() const;
    int getY() const;
    int getDurability() const;
    UnitType getProducedUnit() const;

    // Settery
    void setTeam(Team team);
    void setType(UnitType type);
    void setId(int id);
    void setX(int x);
    void setY(int y);
    void setDurability(int durability);
    void setProducedUnit(UnitType producedUnit);


private:
    Team team;
    UnitType type;
    int id;
    int x;
    int y;
    int durability;
    UnitType producedUnit;
};

bool readStatus(const std::string& filename, std::vector<Unit>& units, int& gold);