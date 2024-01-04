//
// Created by Drizzt on 27/12/2023.
//

#include "Player.h"
int Player::counter = 0;

Player::Player() : ID(++counter) {

}

 std::set<Hexagon*> &Player::getSetOfPlayerHexagons() {
    return setOfPlayerHexagons;
}

const int Player::getId() const {
    return ID;
}
