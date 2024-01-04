#pragma once


#include <set>

#include <iostream>
#include "Hexagon.h"

class Hexagon;

class Player {

private:

    static int counter;
    const int ID;
//    Used to track player points
    std::set<Hexagon> setOfPlayerHexagons;


public:

    Player();

    const int getId() const;

    const std::set<Hexagon> &getSetOfPlayerHexagons();

};



