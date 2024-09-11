#include "test.h"

#include <stdio.h>
#include <math.h>

const int kRadius = 250;
const Vector3D kViewer = {0, 0, 500};
const int kSpeedButtonControl = 50;

void DrawShere3D (const Vector3D& light, sf::RenderWindow& window)
{
    sf::VertexArray points(sf::Points, kHeightWindow * 2);

    for (int i = -kWidthWindow; i < kWidthWindow; i++)
    {
        for (int j = -kHeightWindow; j < kHeightWindow; j++)
        {
            int r1 = i * i + j * j;
            int z = sqrt (kRadius * kRadius - r1);

            Vector3D point {i, j, z};

            if (r1 <= kRadius * kRadius)
            {   
                double brightnessCoef = CalculateCosAngle (point, light - point);
                // double glareCoef      = 
                //     cos (acos(CalculateCosAngle (point, kViewer - point)) -
                //          acos(CalculateCosAngle (point, light  - point)));

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

            
                points[j + kHeightWindow] = 
                    sf::Vertex(sf::Vector2f(i + kWidthWindow, j + kHeightWindow), 
                                sf::Color (color, color, color));
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

    for (double i = 0; i > -M_PI * 2; i -= 0.01)
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

void TestQuick (sf::RenderWindow& window)
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
        Vector v {pos.x - kWidthWindow, -pos.y + kHeightWindow};
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
        Vector3D light {pos.x - kWidthWindow, pos.y - kHeightWindow, 450};

        DrawShere3D (light, window);

        DisplayWindow(window);
    }
}

void ButtonControlShrere (sf::RenderWindow& window)
{
    bool draw = false;

    Vector3D light {kWidthWindow, kHeightWindow, 450};
    const Vector3D shiftUp    {0, -kSpeedButtonControl, 0};
    const Vector3D shiftDown  {0,  kSpeedButtonControl, 0};
    const Vector3D shiftLeft  {-kSpeedButtonControl, 0, 0};
    const Vector3D shiftRight { kSpeedButtonControl, 0, 0};

    while (true)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                return;
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {

                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    if (IsButtonPressed (pos, kButtonOffOn))
                    {
                        if (draw) draw = false; else draw = true;
                    }
                    if (IsButtonPressed (pos, kButtonUp))
                        light = light + shiftUp;
                    if (IsButtonPressed (pos, kButtonDown))
                        light = light + shiftDown;
                    if (IsButtonPressed (pos, kButtonLeft))
                        light = light + shiftLeft;
                    if (IsButtonPressed (pos, kButtonRight))
                        light = light + shiftRight;   
                }
            }
        }
        
        CleanWindow (window);

        DrawButton (kButtonOffOn, window);
        DrawButton (kButtonUp,    window);
        DrawButton (kButtonLeft,  window);
        DrawButton (kButtonDown,  window);
        DrawButton (kButtonRight, window);

        if (draw) DrawShere3D (light, window);

        DisplayWindow(window);
    }
}