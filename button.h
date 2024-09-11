#ifndef STL_BUTTON
#define STL_BUTTON

#include "vectorDec.h"
#include <SFML/Graphics.hpp>

enum ButtonPressed
{
    offOn, 
    up, 
    down, 
    left, 
    right
};

struct Button
{
    VectorDec corner;
    VectorDec size;
};

const Button kButtonOffOn = {.corner {50, 50},   .size {75, 75}};
const Button kButtonUp    = {.corner {675, 50},  .size {50, 50}};
const Button kButtonLeft  = {.corner {625, 100}, .size {50, 50}};
const Button kButtonDown  = {.corner {675, 150}, .size {50, 50}};
const Button kButtonRight = {.corner {725, 100}, .size {50, 50}};

bool IsButtonPressed (const sf::Vector2i& pos, const Button& button);
ButtonPressed ComputeButtonPressed (const sf::Vector2i& pos);

#endif /* STL_BUTTON */