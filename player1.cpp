#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

bool readMap(const std::string& map_src, std::vector<std::vector<int>>& map){
    std::ifstream file(map_src);
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku " << map_src << '\n';
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

bool readStatus(const std::string& src_status, std::vector<std::string>& status){
    std::ifstream file(src_status);
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku " << src_status << '\n';
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        status.push_back(line);
    }
    return true;
}


int main(int argc, char* argv[]) {
    std::string src_map, src_status, src_orders;
    int time_limit;
    std::vector<std::vector<int>> map;
    std::vector<std::string> status;

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
        std::cerr << "Bład wczytywania mapy!\n";
        return 1;
    }

    if(!readStatus(src_status, status)){
        std::cerr << "Bład wczytywania statusu!\n";
        return 1;
    }




    return 0;
}
