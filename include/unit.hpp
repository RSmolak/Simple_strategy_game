/**
 * @file Unit.h
 * @brief Deklaracja klasy Unit oraz powiązanych klas i enumeracji.
 */

#pragma once

#include <string>
#include <vector>
#include <map>

/**
 * @enum Team
 * @brief Enumeracja drużyn.
 */
enum class Team { PLAYER, ENEMY };

/**
 * @enum UnitType
 * @brief Enumeracja typów jednostek.
 */
enum class UnitType { K, S, A, P, C, R, W, B, NONE };

/**
 * @struct UnitProperties
 * @brief Struktura przechowująca właściwości jednostek.
 */
struct UnitProperties {
    int speed;          ///< Prędkość jednostki.
    int cost;           ///< Koszt jednostki.
    int range;          ///< Zasięg jednostki.
    int productionTime; ///< Czas produkcji jednostki.
};

/**
 * @class UnitTypeData
 * @brief Klasa przechowująca dane o właściwościach jednostek.
 */
class UnitTypeData {
public:
    static const std::map<UnitType, UnitProperties> data; ///< Mapa przechowująca dane o właściwościach jednostek.
};

/**
 * @class Unit
 * @brief Klasa reprezentująca jednostkę.
 */
class Unit {
public:
    /**
     * @brief Konstruktor klasy Unit.
     *
     * @param team Drużyna jednostki.
     * @param type Typ jednostki.
     * @param id Identyfikator jednostki.
     * @param x Współrzędna x jednostki.
     * @param y Współrzędna y jednostki.
     * @param durability Wytrzymałość jednostki.
     * @param producedUnit Typ produkowanej jednostki (domyślnie UnitType::NONE).
     */
    Unit(Team team, UnitType type, int id, int x, int y, int durability, UnitType producedUnit = UnitType::NONE);
    
    /**
     * @brief Wyświetla informacje o jednostce.
     */
    void display() const;

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
    Team team;              ///< Drużyna jednostki.
    UnitType type;          ///< Typ jednostki.
    int id;                 ///< Identyfikator jednostki.
    int x;                  ///< Współrzędna x jednostki.
    int y;                  ///< Współrzędna y jednostki.
    int durability;         ///< Wytrzymałość jednostki.
    int speed;              ///< Prędkość jednostki.
    int cost;               ///< Koszt jednostki.
    int range;              ///< Zasięg jednostki.
    int productionTime;     ///< Czas produkcji jednostki.
UnitType producedUnit; ///< Typ produkowanej jednostki.
};

/**

@brief Funkcja odczytująca stan gry z pliku.
@param filename Nazwa pliku ze stanem gry.
@param units Wektor jednostek do zapełnienia.
@param gold Liczba złota do zapełnienia.
@return Zwraca wartość true, jeśli odczyt się powiedzie, false w przeciwnym razie.
*/
bool readStatus(const std::string& filename, std::vector<Unit>& units, int& gold);