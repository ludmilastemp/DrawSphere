#include "GrLib.h"

const int COEF_HAND = 7;

void DrawLine (Vector v, Vector n, sf::RenderWindow& window);

void DrawVector (Vector v, sf::RenderWindow& window)
{
    Vector vTemp = {GetX(v), GetY(v)};
    Vector vSmall = {-vTemp.x/COEF_HAND, -vTemp.y/COEF_HAND};
    Vector vPer  = PerVector (vSmall);
    Vector left  = SumVector (vSmall, vPer);
    Vector right = SumVector (vSmall, SwapVector(vPer));

    DrawLine (vTemp, {}, window);
    DrawLine (left,  vTemp, window);
    DrawLine (right, vTemp, window);
}

void DrawLine (Vector v, Vector n, sf::RenderWindow& window)
{
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(c00.x + n.x, c00.y - n.y)),
        sf::Vertex(sf::Vector2f(c00.x + n.x + v.x, c00.y - n.y - v.y))
    };

    window.draw(line, 100, sf::Lines);
}

void CleanWindow (sf::RenderWindow& window)
{
    sf::Vertex line1[] =
    {
        sf::Vertex(sf::Vector2f(400, 0)),
        sf::Vertex(sf::Vector2f(400, 600))
    };

    sf::Vertex line2[] =
    {
        sf::Vertex(sf::Vector2f(0, 300)),
        sf::Vertex(sf::Vector2f(800, 300))
    };

    window.clear();

    window.draw(line1, 100, sf::Lines);
    window.draw(line2, 100, sf::Lines);
}

