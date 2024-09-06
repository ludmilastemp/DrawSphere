#include <stdio.h>
#include "GrLib.h"
#include "vector.h"

void FollowMouse (sf::RenderWindow& window)
{
    while (true)
    {
        CleanWindow (window);

        sf::Vector2i pos = sf::Mouse::getPosition(window);
        Vector v {pos.x - 400, -pos.y + 300};
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

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    while (window.isOpen())
    {
        i++;
        if (i == 2) return 0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        CleanWindow (window);

        Test (window);
        //FollowMouse (window);


        DisplayWindow(window);
    }

    return 0;
}