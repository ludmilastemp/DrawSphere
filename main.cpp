#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "test.h"

// ВЕЗДЕ const&

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
        if (i == 2) return 0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        CleanWindow (window);

        TestQuick (window);
        // FollowMouseVector (window);
        // FollowMouseShrere (window);
        // ButtonControlShrere (window);

        DisplayWindow(window);
    }

    return 0;
}