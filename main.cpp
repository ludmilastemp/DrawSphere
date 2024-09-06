#include <stdio.h>
#include "GrLib.h"
#include "vector.h"

// ВЕЗДЕ const&

const int RADIUS = 250;

void DrawShere (sf::RenderWindow& window)
{
    sf::VertexArray points(sf::Points, HEIGHT_WINDOW * 2);

    for (int i = -WIDTH_WINDOW; i < WIDTH_WINDOW; i++)
    {
        for (int j = -HEIGHT_WINDOW; j < HEIGHT_WINDOW; j++)
        {
            int r1 = i * i + j * j;
            if (r1 <= RADIUS * RADIUS)
            {
                int color = (RADIUS * RADIUS - r1) % 255;
                points[j + HEIGHT_WINDOW] = 
                    sf::Vertex(sf::Vector2f(i + WIDTH_WINDOW, j + HEIGHT_WINDOW), 
                               sf::Color (color, color, color));
            }
            else 
            {
                points[j + HEIGHT_WINDOW] = sf::Vertex(sf::Vector2f(i + WIDTH_WINDOW, j + HEIGHT_WINDOW), sf::Color::Green);
            }
        }
        window.draw(points);
    } 
}

void FollowMouse (sf::RenderWindow& window)
{
    while (true)
    {
        CleanWindow (window);

        sf::Vector2i pos = sf::Mouse::getPosition(window);
        Vector v {pos.x - WIDTH_WINDOW, -pos.y + HEIGHT_WINDOW};
        DrawVector (v, window);

        DisplayWindow(window);
    }
}

void PrintCyrcle (sf::RenderWindow& window)
{
    Vector v {250, 0.0};

    for (int i = 0; i > -360; i--)
    {
        v.setPhi(i);

        CleanWindow (window);

        DrawVector (v, window);

        DisplayWindow(window);
    }
}

void PrintRect (sf::RenderWindow& window)
{
    Vector v {-350, 250};

    for (int i = -350; i < 350; i++)
    {
        v.setX(i);

        CleanWindow (window);

        DrawVector (v, window);

        DisplayWindow(window);
    }

    for (int i = 250; i > -250; i--)
    {
        v.setY(i);

        CleanWindow (window);

        DrawVector (v, window);

        DisplayWindow(window);
    }

    for (int i = 350; i > -350; i--)
    {
        v.setX(i);

        CleanWindow (window);

        DrawVector (v, window);

        DisplayWindow(window);
    }

    for (int i = -250; i < 250; i++)
    {
        v.setY(i);

        CleanWindow (window);

        DrawVector (v, window);

        DisplayWindow(window);
    }
}

void Test (sf::RenderWindow& window)
{
    // Vector v1 {50, 50};
    // Vector v2 {100, 10};

    // Vector v3 = SumVector (v1, v2);
    // Vector v4 = PerVector (v1);

    PrintCyrcle (window);
    PrintCyrcle (window);
    PrintCyrcle (window);
    PrintRect (window);
}

int main()
{
    printf ("Start\n");
    int i = 0;

    sf::RenderWindow window(sf::VideoMode(WIDTH_WINDOW * 2, HEIGHT_WINDOW * 2), "SFML works!");
    sf::Image img;
    img.create(WIDTH_WINDOW * 2, HEIGHT_WINDOW * 2, sf::Color::Black);

    while (window.isOpen())
    {
        i++;
        // if (i == 2) return 0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        CleanWindow (window);

        // Test (window);
        // FollowMouse (window);
        DrawShere (window);

        DisplayWindow(window);
    }

    return 0;
}