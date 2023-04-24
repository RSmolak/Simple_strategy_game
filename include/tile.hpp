#pragma once

/**
 * @brief Klasa reprezentująca pole na mapie.
 * 
 * Klasa zawiera zmienna typu char reprezentujaca rodzaj terenu:
 * '0' - Droga po której mogą przemieszczać się jednostki
 * '9' - Przeszkoda, jednostki nie mogą zatrzymać się na tym polu, w przypadku wystarczającej ilości punktów ruchu przeszkody można przeskakiwać.
 * '1' - Baza pierwszego programu gracza
 * '2' - Baza drugiego programu gracza
 * '6' - Kopalnia
 * 
 */
class Tile{
private:
    /// @brief Zmienna reprezentujaca pole.
    char type;

public:

    /// @brief Kontruktor bezparametryczny obiektu Tile
    Tile();

    /// @brief Konstruktor przypisujący wartość do zmiennej Tile
    /// @param value Wartość określająca rodzaj terenu
    Tile(char value);

    /// @brief Funkcja zwracajaca pole reprezentujace teren mapy w zadanym miejcu
    /// @param x Wspolrzedna x wybranego pola
    /// @param y Wspolrzedna y wybranego pola
    /// @return zmienna typu char reprezentujaca pole 
    char get()const {return type;};

    /// @brief Sprawdza czy pole jest przeszkodą
    /// @return Warunek logiczny czy zmienna jest przeszkodą
    bool isObstacle()const {return type=='9';};

    /// @brief Sprawdza czy pole jest bazą gracza 1
    /// @return Warunek logiczny czy zmienna jest bazą gracza 1
    bool isPlayer1Base()const {return type=='1';};

    /// @brief Sprawdza czy pole jest bazą gracza 2
    /// @return Warunek logiczny czy zmienna jest bazą gracza 2
    bool isPlayer2Base()const {return type=='2';};

    /// @brief Sprawdza czy pole jest kokpalnią
    /// @return Warunek logiczny czy zmienna jest kopalnią 
    bool isMine()const {return type=='6';};
};