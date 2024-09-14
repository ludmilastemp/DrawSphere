#include "test.h"

#include <stdio.h>  //
#include <math.h>   //
#include <assert.h> //

double MAGIC = 0.02;

const int kRadius = 250;
const int kLightCircleSize = 7; // от 1 до 10
const int kLightZ = 1000;
const int kLightIntervalTest  = 1500;
const int kSpeedSphereTest    = 250;
const int kSpeedButtonControl = 50;

const Vector3D kViewer  = {0, 0, 300};

const Color kLightColor = {0, 1, 1};
const Color kMaterColor = {0, 1, 1};
const Color kAmbieColor = {0, 0.05, 0.05};

Color IdentifySourceColor (const Vector3D& point, const Vector3D& light)
{
    double diffuseCoef = CalculateCosAngle (point, light - point);
    Vector3D otr       = ReflectVector     (light - point, point);
    double glareCoef   = CalculateCosAngle (otr, kViewer - point);

    if (diffuseCoef < 0) diffuseCoef = 0;
    if (glareCoef < 0)   glareCoef = 0;

    glareCoef   = pow (glareCoef, 15);
    diffuseCoef = pow (diffuseCoef, 11 - kLightCircleSize);

    Color color = kMaterColor * kAmbieColor                         + 
                  kMaterColor * kLightColor * (MAGIC + diffuseCoef) + 
                                kLightColor * glareCoef;

    return color;
}

void DrawSphere3D (const Vector3D& light, GraphicsCtx& ctx)
{
    sf::VertexArray points(sf::Points, kHeightWindow * 2);

    for (int i = -kWidthWindow; i < kWidthWindow; i++)
    {
        for (int j = -kHeightWindow; j < kHeightWindow; j++)
        {
            int r1 = i * i + j * j;
            double z = sqrt (kRadius * kRadius - r1);

            Vector3D point {i, j, z};

            if (r1 <= kRadius * kRadius)
            {   
                Color lightSource1 = IdentifySourceColor (point, light);
                Color lightSource2 = IdentifySourceColor (point, {300, -400, 800});

                Color color = lightSource1 + lightSource2;

                color.clamp();
                color = color * 255;

                points[j + kHeightWindow] = 
                    sf::Vertex(sf::Vector2f(i + kWidthWindow, j + kHeightWindow), 
                                sf::Color (color.r, color.g, color.b));
            }
        }
        ctx.window.draw(points);
    } 
}

void TestSphere3D (GraphicsCtx& ctx)
{
    Vector3D light {-kLightIntervalTest, -kLightIntervalTest, kLightZ};
    int temp = kSpeedSphereTest;

    for (; light.x < kLightIntervalTest; light.x += temp)
    {
        CleanWindow (ctx);

        DrawSphere3D (light, ctx);

        DisplayWindow(ctx);
    }

    for (; light.y < kLightIntervalTest; light.y += temp)
    {
        CleanWindow (ctx);

        DrawSphere3D (light, ctx);

        DisplayWindow(ctx);
    }

    for (; light.x >- kLightIntervalTest; light.x -= temp)
    {
        CleanWindow (ctx);

        DrawSphere3D (light, ctx);

        DisplayWindow(ctx);
    }

    for (; light.y >- kLightIntervalTest; light.y -= temp)
    {
        CleanWindow (ctx);

        DrawSphere3D (light, ctx);

        DisplayWindow(ctx);
    }
}

void PrintCyrcle (GraphicsCtx& ctx)
{
    Vector v {250, 0.0};

    for (double i = 0; i > -M_PI * 2; i -= 0.01)
    {
        v.setPhi(i);

        CleanWindow (ctx);

        DrawVector (v, ctx);

        DisplayWindow(ctx);
    }
}

void PrintRect (GraphicsCtx& ctx)
{
    Vector v {-350, 250};

    for (int i = -350; i < 350; i++)
    {
        v.setX(i);

        CleanWindow (ctx);

        DrawVector (v, ctx);

        DisplayWindow(ctx);
    }

    for (int i = 250; i > -250; i--)
    {
        v.setY(i);

        CleanWindow (ctx);

        DrawVector (v, ctx);

        DisplayWindow(ctx);
    }

    for (int i = 350; i > -350; i--)
    {
        v.setX(i);

        CleanWindow (ctx);

        DrawVector (v, ctx);

        DisplayWindow(ctx);
    }

    for (int i = -250; i < 250; i++)
    {
        v.setY(i);

        CleanWindow (ctx);

        DrawVector (v, ctx);

        DisplayWindow(ctx);
    }
}

void TestQuick (GraphicsCtx& ctx)
{
    // PrintCyrcle (ctx);
    // PrintCyrcle (ctx);
    // PrintCyrcle (ctx);
    // PrintRect   (ctx);
    // for (; MAGIC < 0.3; MAGIC += 0.03)
    TestSphere3D (ctx);
}

void FollowMouseVector (GraphicsCtx& ctx)
{
    while (true)
    {
        CleanWindow (ctx);

        sf::Vector2i pos = sf::Mouse::getPosition(ctx.window);
        Vector v {pos.x - kWidthWindow, -pos.y + kHeightWindow};
        DrawVector (v, ctx);

        DisplayWindow(ctx);
    }
}

void FollowMouseSphere (GraphicsCtx& ctx)
{
    while (true)
    {
        CleanWindow (ctx);

        sf::Vector2i pos = sf::Mouse::getPosition(ctx.window);
        Vector3D light {pos.x - kWidthWindow, pos.y - kHeightWindow, kLightZ};

        DrawSphere3D (light, ctx);

        DisplayWindow(ctx);
    }
}

void ButtonControlSphere (GraphicsCtx& ctx)
{
    bool draw = false;

    Vector3D light {kWidthWindow, kHeightWindow, kLightZ};
    const Vector3D shiftUp    {0, -kSpeedButtonControl, 0};
    const Vector3D shiftDown  {0,  kSpeedButtonControl, 0};
    const Vector3D shiftLeft  {-kSpeedButtonControl, 0, 0};
    const Vector3D shiftRight { kSpeedButtonControl, 0, 0};

    while (true)
    {
        sf::Event event;
        while (ctx.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                return;
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {

                    sf::Vector2i pos = sf::Mouse::getPosition(ctx.window);
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
        
        CleanWindow (ctx);

        DrawButton (kButtonOffOn, ctx);
        DrawButton (kButtonUp,    ctx);
        DrawButton (kButtonLeft,  ctx);
        DrawButton (kButtonDown,  ctx);
        DrawButton (kButtonRight, ctx);

        if (draw) DrawSphere3D (light, ctx);

        DisplayWindow(ctx);
    }
}