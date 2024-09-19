#include "testFollowMouse.h"

#include <stdio.h>  //
#include <math.h>   //
#include <assert.h> //

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
    Scene scene;

    Sphere sphere     {true,  250, {0, 1, 1}, {0, 0.005, 0.005}};
    Light  light      {false, {0, 0, 700}, {0, 1, 1}}; 

    scene.add (*(Object*)&sphere);
    scene.add (*(Object*)&light);

    while (true)
    {
        CleanWindow (ctx);

        sf::Vector2i pos = sf::Mouse::getPosition(ctx.window);
        light.coord.x = pos.x - kWidthWindow;
        light.coord.y = pos.y - kHeightWindow;

        scene.draw (ctx);

        DisplayWindow(ctx);
    }
}