#include <stdio.h>
#include "GrLib.h"
#include "vector.h"

void PrintCyrcle (sf::RenderWindow& window)
{
    Vector v = CtorPolVector (250, 0);

    for (int i = 0; i < 360; i++)
    {
        v = SetA(v, i);

        CleanWindow (window);

        DrawVector (v, window);

        window.display();
    }
}

void PrintRect (sf::RenderWindow& window)
{
    Vector v = CtorDecVector (-350, 250);

    for (int i = -350; i < 350; i++)
    {
        v = SetX(v, i);

        CleanWindow (window);

        DrawVector (v, window);

        window.display();
    }

    for (int i = 250; i > -250; i--)
    {
        v = SetY(v, i);

        CleanWindow (window);

        DrawVector (v, window);

        window.display();
    }

    for (int i = 350; i > -350; i--)
    {
        v = SetX(v, i);

        CleanWindow (window);

        DrawVector (v, window);

        window.display();
    }

    for (int i = -250; i < 250; i++)
    {
        v = SetY(v, i);

        CleanWindow (window);

        DrawVector (v, window);

        window.display();
    }
}

void Test (sf::RenderWindow& window)
{
    Vector v1 = { 50, 50 };
    Vector v2 = { 100, 10 };

    Vector v3 = SumVector (v1, v2);
    Vector v4 = PerVector (v1);

    PrintCyrcle (window);
    PrintCyrcle (window);
    PrintCyrcle (window);
    PrintRect (window);
}

int main()
{
    printf ("Start\n");

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        CleanWindow (window);

        Test(window);


        window.display();
    }

    return 0;
}