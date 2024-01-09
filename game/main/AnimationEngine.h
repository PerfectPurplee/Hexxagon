#pragma once

#include <SFML/Graphics.hpp>

class AnimationEngine {

private:

    int BackgroundAnimationSpeed;

public:


    static void AnimateBackground(std::vector<sf::CircleShape> &vectorOfElementsToAnimate);

};



