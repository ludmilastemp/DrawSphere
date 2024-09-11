#include <stdio.h>
#include "GrLib.h"
#include "vector.h"
#include "vector3D.h"

// ВЕЗДЕ const&

const int RADIUS = 250;
const Vector3D VIEWER = {0, 0, 500};

void DrawShere3D (const Vector3D& light, sf::RenderWindow& window)
{
    sf::VertexArray points(sf::Points, HEIGHT_WINDOW * 2);

    for (int i = -WIDTH_WINDOW; i < WIDTH_WINDOW; i++)
    {
        for (int j = -HEIGHT_WINDOW; j < HEIGHT_WINDOW; j++)
        {
            int r1 = i * i + j * j;
            int z = sqrt (RADIUS * RADIUS - r1);

            Vector3D point {i, j, z};

            if (r1 <= RADIUS * RADIUS)
            {   
                double brightnessCoef = CalculateCosAngle (point, light - point);
                double glareCoef      = 
                    cos (acos(CalculateCosAngle (point, VIEWER - point)) -
                         acos(CalculateCosAngle (point, light  - point)));

                // double glareCoefPow = pow (glareCoef, 30);

                int color = 0;
                if (brightnessCoef > 0)
                {
                    // if (glareCoef > 0)
                    // {
                    //     if (glareCoef < brightnessCoef)
                    //     if (glareCoefPow < brightnessCoef)
                    //     {
                    //        color = glareCoef * 250;
                    //        color = glareCoefPow * 255;
                    //     }
                    // }
                    // {
                        color = brightnessCoef * 255;
                    // }
                }

            
                points[j + HEIGHT_WINDOW] = 
                    sf::Vertex(sf::Vector2f(i + WIDTH_WINDOW, j + HEIGHT_WINDOW), 
                                sf::Color (color, color, color));
            }
            else 
            {
                points[j + HEIGHT_WINDOW] = 
                    sf::Vertex(sf::Vector2f(i + WIDTH_WINDOW, j + HEIGHT_WINDOW), 
                               sf::Color::Black);
            }
        }
        window.draw(points);
    } 
}

void TestShere3D (sf::RenderWindow& window)
{
    Vector3D light {-350, -350, 450};
    int temp = 50;

    for (; light.x < 350; light.x += temp)
    {
        CleanWindow (window);

        DrawShere3D (light, window);

        DisplayWindow(window);
    }

    for (; light.y < 350; light.y += temp)
    {
        CleanWindow (window);

        DrawShere3D (light, window);

        DisplayWindow(window);
    }

    for (; light.x >- 350; light.x -= temp)
    {
        CleanWindow (window);

        DrawShere3D (light, window);

        DisplayWindow(window);
    }

    for (; light.y >- 350; light.y -= temp)
    {
        CleanWindow (window);

        DrawShere3D (light, window);

        DisplayWindow(window);
    }
}

void PrintCyrcle (sf::RenderWindow& window)
{
    Vector v {250, 0.0};

    for (double i = 0; i > -PI * 2; i -= 0.01)
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
    PrintRect   (window);
    TestShere3D (window);
}

void FollowMouseVector (sf::RenderWindow& window)
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

void FollowMouseShrere (sf::RenderWindow& window)
{
    while (true)
    {
        CleanWindow (window);

        sf::Vector2i pos = sf::Mouse::getPosition(window);
        Vector3D light {pos.x - WIDTH_WINDOW, pos.y - HEIGHT_WINDOW, 450};

        DrawShere3D (light, window);

        DisplayWindow(window);
    }
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
        if (i == 2) return 0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        CleanWindow (window);

        Test (window);
        // FollowMouseVector (window);
        // FollowMouseShrere (window);

        DisplayWindow(window);
    }

    return 0;
}