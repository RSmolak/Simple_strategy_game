#include "../include/map.hpp"

Map::Map(){}

bool Map::read(const std::string &src_file)
{
    std::ifstream file("data/" + src_file);
    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku " << "../data/" << src_file << '\n';
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<Tile> temp;
        for(char c : line){
            temp.push_back(Tile(c));
        }
        this->tiles.push_back(temp);
    }
    return true;
}