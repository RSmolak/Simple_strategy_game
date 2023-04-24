#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../include/unit.hpp"
#include "../include/map.hpp"

bool checkCommandLineArguments(const std::string& src_map, const std::string& src_status, const std::string& src_orders, const int& time_limit);

bool readStatus(const std::string& src_status, std::vector<Unit>& units, int& gold);

void displayUnitsAndGold(const std::vector<Unit>& units, int gold);


int main(int argc, char* argv[]) {
    std::string src_map, src_status, src_orders;
    int time_limit;
    Map map = Map();
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

    if(!map.read(src_map)){
        std::cerr << "Blad wczytywania mapy!\n";
        return 1;
    }

    if(!readStatus(src_status, units, gold)){
        std::cerr << "Blad wczytywania statusu!\n";
        return 1;
    }

    displayUnitsAndGold(units, gold);
    map.display();

    return 0;
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
        unit.display();
    }
}