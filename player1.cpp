#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Unit.hpp"

bool checkCommandLineArguments(const std::string& src_map, const std::string& src_status, const std::string& src_orders, const int& time_limit);

bool readMap(const std::string& map_src, std::vector<std::vector<int>>& map);

bool readStatus(const std::string& src_status, std::vector<Unit>& units, int& gold);

void displayUnitsAndGold(const std::vector<Unit>& units, int gold);


int main(int argc, char* argv[]) {
    std::string src_map, src_status, src_orders;
    int time_limit;
    std::vector<std::vector<int>> map;
    int gold;
    std::vector<Unit> units;

    if (argc >= 4) {
        src_map = argv[1];
        src_status = argv[2];
        src_orders = argv[3];
        time_limit = std::stoi(argv[4] ? argv[4] : "5");
    } 
    else {
        std::cerr << "Nieprawidlowa liczba argumentow\n";
        return 1;

    }

    if(!checkCommandLineArguments(src_map, src_status, src_orders, time_limit)){
        return 1;
    }

    if(!readMap(src_map, map)){
        std::cerr << "Blad wczytywania mapy!\n";
        return 1;
    }

    if(!readStatus(src_status, units, gold)){
        std::cerr << "Blad wczytywania statusu!\n";
        return 1;
    }

    displayUnitsAndGold(units, gold);

    return 0;
}

bool readMap(const std::string& map_src, std::vector<std::vector<int>>& map){
    std::ifstream file(map_src);
    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku " << map_src << '\n';
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        for (char c : line) {
            row.push_back(c - '0');
        }
        map.push_back(row);
    }
    return true;
}

bool checkCommandLineArguments(const std::string& src_map, const std::string& src_status, const std::string& src_orders, const int& time_limit){
    if(src_map!="mapa.txt"){
        std::cerr << "Niepoprawna nazwa pliku przekazana w pierwszym argumencie. Powinno byc \"mapa.txt\".\n";
        return false;
    }
    else if(src_status!="status.txt"){
        std::cerr << "Niepoprawna nazwa pliku przekazana w drugim argumencie. Powinno byc \"status.txt\".\n";
        return false;
    }
    else if(src_orders!="rozkazy.txt"){
        std::cerr << "Niepoprawna nazwa pliku przekazana w trzecim argumencie. Powinno byc \"rozkazy.txt\".\n";
        return false;
    }
    else if(time_limit <= 0){
        std::cerr << "Podany czas musi byc wiekszy od 0\n";
        return false;
    }
    return true;
}

void displayUnitsAndGold(const std::vector<Unit>& units, int gold) {
    std::cout << "Zloto: " << gold << '\n';
    std::cout << "Jednostki:" << '\n';

    for (const Unit& unit : units) {
        std::string teamName = (unit.getTeam() == Team::PLAYER) ? "PLAYER" : "ENEMY";
        char typeChar = 'A' + static_cast<char>(unit.getType());
        char producedUnitChar = (unit.getProducedUnit() == UnitType::NONE) ? '0' : 'A' + static_cast<char>(unit.getProducedUnit());

        std::cout << "Team: " << teamName << ", Type: " << typeChar << ", ID: " << unit.getId()
                  << ", X: " << unit.getX() << ", Y: " << unit.getY() << ", Durability: " << unit.getDurability()
                  << ", Produced Unit: " << producedUnitChar << '\n';
    }
}