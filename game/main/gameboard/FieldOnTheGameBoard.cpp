#include "../../Entities/Hexagon.h"
#include <SFML/Graphics.hpp>
#include <valarray>
#include <cassert>

struct HexCoordinates {
    const int q;
    const int r;
    const int s;

    HexCoordinates(int q_, int r_, int s_) : q(q_), r(r_), s(s_) {
        assert(q + r + s == 0);
    }


};

struct FieldOnTheGameBoard {

    sf::ConvexShape hexagonField;
    int column{};
    int row{};
    Hexagon *hexagon;

    HexCoordinates *hexCoordinates;

    FieldOnTheGameBoard(int column, int row) : hexagon(nullptr), hexCoordinates(nullptr) {
        this->column = column;
        this->row = row;


//        sets visual representation of a game field
        this->hexagonField.setPointCount(6);

        for (int i = 0; i < 6; ++i) {
            hexagonField.setPoint(i, hexagonPoint(50, 50, 40, i));
        }

        hexagonField.setOutlineThickness(-5);
        hexagonField.setFillColor(sf::Color(88, 22, 145));
        hexagonField.setOutlineColor(sf::Color(139, 34, 230));

    }

    FieldOnTheGameBoard(int q, int r, int s) : hexagon(nullptr) {
       this->hexCoordinates = new HexCoordinates(q, r, s);


//        sets visual representation of a game field
        this->hexagonField.setPointCount(6);

        for (int i = 0; i < 6; ++i) {
            hexagonField.setPoint(i, hexagonPoint(50, 50, 40, i));
        }

        hexagonField.setOutlineThickness(-3);
        hexagonField.setFillColor(sf::Color(88, 22, 145));
        hexagonField.setOutlineColor(sf::Color(139, 34, 230));

    }

    static sf::Vector2f hexagonPoint(float centerX, float centerY, float size, int i) {
        float angle = 60.0f * i;
        float radianAngle = 3.14159f / 180.0f * angle;
        float x = centerX + size * std::cos(radianAngle);
        float y = centerY + size * std::sin(radianAngle);
        return {x, y};
    }
};

