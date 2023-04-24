#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "tile.hpp"



/**
 * @class Map
 * @brief Klasa reprezentująca mapę gry.
 * 
 * Klasa Map przechowuje informacje o wysokosci i szerokosci mapy, a takze zawiera macierz obiektow typu Tile reprezentujacych teren.
 * 
 * UWAGA! tiles zawiera tylko informacje o terenie. Nie zawiera informacji o jednostkach.
 */
class Map{
private:
    /**
     * @brief Szerokosc mapy
     * 
     */
    int width;

    /**
     * @brief Wysokosc mapy
     * 
     */
    int height;

    /**
     * @brief Macierz pol mapy - uksztaltowanie terenu
     * 
     */
    std::vector<std::vector<Tile>> tiles;

public:
    /**
     * @brief Kontruktor obiektu mapy.
     * 
     */
    Map();
    /**
     * @brief Funkcja zapisująca mapę z pliku do obiektu
     * 
     * @param src_file plik txt z mapa
     * @return true przepisywanie pomyslne
     * @return false przepisywanie niepomyslne
     */
    bool read(const std::string& src_file);
    /**
     * @brief Zwraca obiekt tile
     * 
     * @param wspolrzedna x 
     * @param wspolrzedna y 
     * @return Tile 
     */
    Tile getTile(int x, int y) const {return tiles[y][x];};

    /**
     * @brief Funkcja testowa wypisująca mapę w konsoli.
     * 
     */
    void display() const;
};