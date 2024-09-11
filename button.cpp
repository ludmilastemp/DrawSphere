#include "button.h"

#include <SFML/Graphics.hpp> //// delete

bool IsButtonPressed (const sf::Vector2i& pos, const Button& button)
{
    return 
        button.corner.x <= pos.x && 
                            pos.x <= button.corner.x + button.size.x &&
        button.corner.y <= pos.y && 
                            pos.y <= button.corner.y + button.size.y;

}

ButtonPressed ComputeButtonPressed (const sf::Vector2i& pos)
{
    if (IsButtonPressed (pos, kButtonOffOn))
        return offOn;
    if (IsButtonPressed (pos, kButtonUp))
        return up;
    if (IsButtonPressed (pos, kButtonDown))
        return down;
    if (IsButtonPressed (pos, kButtonLeft))
        return left;
    if (IsButtonPressed (pos, kButtonRight))
        return right;
    return offOn;
}
