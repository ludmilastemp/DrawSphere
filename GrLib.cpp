#include "GrLib.h"

const int ARROW_LENGTH = 25;
const int COEF_HAND = 7;

void DrawLine (Vector& v, Vector n, sf::RenderWindow& window);

void DrawVector (Vector& v, sf::RenderWindow& window)
{
    // Vector vSmall {v.getX(), v.getY()};
    // vSmall = !vSmall;
    // vSmall = vSmall * ARROW_LENGTH;

    Vector vSmall = {v.getX(), v.getY()};

    vSmall = vSmall / COEF_HAND;

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
        sf::Vertex(sf::Vector2f(WIDTH_WINDOW + n.getX(), HEIGHT_WINDOW - n.getY())),
        sf::Vertex(sf::Vector2f(WIDTH_WINDOW + n.getX() + v.getX(), HEIGHT_WINDOW - n.getY() - v.getY()))
    };

    window.draw(line, 100, sf::Lines);
}

void DrawButton (const Button& button, sf::RenderWindow& window)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(button.size.x_, button.size.y_));
    rectangle.setOutlineColor(sf::Color::Green);
    // rectangle.setOutlineThickness(5);
    rectangle.setPosition(button.corner.x_, button.corner.y_);
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
    //     sf::Vertex(sf::Vector2f(WIDTH_WINDOW, 0)),
    //     sf::Vertex(sf::Vector2f(WIDTH_WINDOW, 600))
    // };

    // sf::Vertex line2[] =
    // {
    //     sf::Vertex(sf::Vector2f(0, HEIGHT_WINDOW)),
    //     sf::Vertex(sf::Vector2f(800, HEIGHT_WINDOW))
    // };

    window.clear();

    // window.display();

    // window.draw(line1, 100, sf::Lines);
    // window.draw(line2, 100, sf::Lines);
}

