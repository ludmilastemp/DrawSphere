#include "GrLib.h"

#include <stdio.h>
#include <unistd.h>

void DrawLine (Vector& v, Vector n, sf::RenderWindow& window);

void DrawVector (Vector& v, sf::RenderWindow& window)
{
    // Vector vSmall {v.getX(), v.getY()};
    // vSmall = !vSmall;
    // vSmall = vSmall * kArrowLength;

    Vector vSmall = {v.getX(), v.getY()};

    vSmall = vSmall / kHandCoeff;

    Vector left  = -vSmall + PerpendicularVector (vSmall);
    Vector right = -vSmall - PerpendicularVector (vSmall);

    DrawLine (v, Vector {0, 0}, window);
    DrawLine (left,  v, window);
    DrawLine (right, v, window);
}

void DrawLine (Vector& v, Vector n, sf::RenderWindow& window)
{
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(kWidthWindow + n.getX(), kHeightWindow - n.getY())),
        sf::Vertex(sf::Vector2f(kWidthWindow + n.getX() + v.getX(), kHeightWindow - n.getY() - v.getY()))
    };

    window.draw(line, 100, sf::Lines);
}

void DrawButton (const Button& button, sf::RenderWindow& window)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(button.size.x, button.size.y));
    rectangle.setOutlineColor(sf::Color::Green);
    // rectangle.setOutlineThickness(5);
    rectangle.setPosition(button.corner.x, button.corner.y);
    window.draw(rectangle);
}

void DisplayWindow (sf::RenderWindow& window)
{  
    window.display();
}

void CleanWindow (sf::RenderWindow& window)
{
    // sf::Vertex line1[] =
    // {
    //     sf::Vertex(sf::Vector2f(kWidthWindow, 0)),
    //     sf::Vertex(sf::Vector2f(kWidthWindow, 600))
    // };

    // sf::Vertex line2[] =
    // {
    //     sf::Vertex(sf::Vector2f(0, kHeightWindow)),
    //     sf::Vertex(sf::Vector2f(800, kHeightWindow))
    // };

    window.clear();

    // window.display();

    // window.draw(line1, 100, sf::Lines);
    // window.draw(line2, 100, sf::Lines);
}

