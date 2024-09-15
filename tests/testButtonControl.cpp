#include "testButtonControl.h"

void TestButtonControl (GraphicsCtx& ctx)
{
    Scene scene;
    Sphere sphere     {true,  250, {0, 1, 1}, {0, 0.005, 0.005}};
    Light  light      {false, {kWidthWindow, kHeightWindow, 800}, {0, 1, 1}}; 
    scene.add (*(Object*)&sphere);
    scene.add (*(Object*)&light);
                          
    Button buttonOffOn = {true, {50, 50},   {75, 75}, sphere, OffOn};
    Button buttonUp    = {true, {675, 50},  {50, 50}, light,  MoveUp};
    Button buttonLeft  = {true, {625, 100}, {50, 50}, light,  MoveLeft};
    Button buttonDown  = {true, {675, 150}, {50, 50}, light,  MoveDown};
    Button buttonRight = {true, {725, 100}, {50, 50}, light,  MoveRight};

    scene.add (*(Object*)&buttonOffOn);
    scene.add (*(Object*)&buttonUp);
    scene.add (*(Object*)&buttonLeft);
    scene.add (*(Object*)&buttonDown);
    scene.add (*(Object*)&buttonRight);

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
                    for (int i = 0; i < scene.objects.size(); i++)
                    {
                        if (scene.objects[i]->type() == ObjectTypeButton &&
                            IsButtonPressed (pos, *(Button*)(scene.objects[i])))
                        {
                            ((Button*)(scene.objects[i]))->action();
                        }
                    }
                }
            }
        }
        
        CleanWindow (ctx);

        DrawScene (scene, ctx);

        DisplayWindow(ctx);
    }
}