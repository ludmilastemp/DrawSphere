#include "GrLib.h"

#include <stdio.h>
#include <unistd.h>

GraphicsCtx::GraphicsCtx ()
    :window(sf::VideoMode(kWidthWindow * 2, kHeightWindow * 2), "SFML works!")
{
    sf::Image img;
    img.create(kWidthWindow * 2, kHeightWindow * 2, sf::Color::Black);
}

/**************************************************************************/

void DrawLine (Vector& v, Vector n, GraphicsCtx& ctx);

void DrawVector (Vector& v, GraphicsCtx& ctx)
{
    // Vector vSmall {v.getX(), v.getY()};
    // vSmall = !vSmall;
    // vSmall = vSmall * kArrowLength;

    Vector vSmall = {v.getX(), v.getY()};

    vSmall = vSmall / kHandCoeff;

    Vector left  = -vSmall + PerpendicularVector (vSmall);
    Vector right = -vSmall - PerpendicularVector (vSmall);

    DrawLine (v, Vector {0, 0}, ctx);
    DrawLine (left,  v, ctx);
    DrawLine (right, v, ctx);
}

void DrawLine (Vector& v, Vector n, GraphicsCtx& ctx)
{
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(kWidthWindow + n.getX(), kHeightWindow - n.getY())),
        sf::Vertex(sf::Vector2f(kWidthWindow + n.getX() + v.getX(), kHeightWindow - n.getY() - v.getY()))
    };

    ctx.window.draw(line, 100, sf::Lines);
}

void DrawButton (const Button& button, GraphicsCtx& ctx)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(button.size.x, button.size.y));
    rectangle.setOutlineColor(sf::Color::Green);
    // rectangle.setOutlineThickness(5);
    rectangle.setPosition(button.corner.x, button.corner.y);
    ctx.window.draw(rectangle);
}

bool IsWindowOpen (GraphicsCtx& ctx)
{
    return ctx.window.isOpen();
}

void CheckEventCloseWindow (GraphicsCtx& ctx)
{

        sf::Event event;
        while (ctx.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                ctx.window.close();
        }
}

void DisplayWindow (GraphicsCtx& ctx)
{  
    ctx.window.display();
}

void CleanWindow (GraphicsCtx& ctx)
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

    ctx.window.clear();

    // window.display();

    // window.draw(line1, 100, sf::Lines);
    // window.draw(line2, 100, sf::Lines);
}

