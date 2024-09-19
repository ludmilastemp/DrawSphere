#include "testButtonControl.h"

const double kColorSpeed = 0.05;
const double kInitialColorAlpha = 0.15;
const double kInitialShiftAlpha = 0.03;

void ActiveScene (Scene& scene, GraphicsCtx& ctx)
{
    while (true)
    {
        sf::Event event;
        while (ctx.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                return;
            
            // sf::Vector2i pos = sf::Mouse::getPosition(ctx.window);
            for (int i = 0; i < scene.objects.size(); i++)
            {
                switch (scene.objects[i]->type())
                {
                    case (ObjectTypeButton):
                    {
                        Button& button = *(Button*)(scene.objects[i]);
                        sf::Vector2i pos = sf::Mouse::getPosition(ctx.window);

                        if (IsButton (pos, button))
                        {
                            if (event.type == sf::Event::MouseButtonPressed &&
                                event.mouseButton.button == sf::Mouse::Left)
                            {
                                for (int act = 0; act < button.actions.size(); act++)
                                {
                                    button.actions[act]->call();
                                }
                            }
                            if (button.color.a + kColorSpeed < 1) 
                                button.color.a += kColorSpeed;
                        }
                        else 
                        {
                            if (button.color.a - kColorSpeed > kInitialColorAlpha) 
                                button.color.a -= kColorSpeed;
                        }
                        break;
                    }
                    case (ObjectTypeLight):
                    case (ObjectTypeSphere):
                    default: 
                        ;
                }
            }
        }
        
        CleanWindow (ctx);

        DrawScene (scene, ctx);

        DisplayWindow(ctx);
    }
}

void TestButtonControl (GraphicsCtx& ctx)
{
    Scene scene;
    Sphere sphere {true,  250, {1, 1, 1}, {0.005, 0.005, 0.005}};
    Light  light  {false, {kWidthWindow, kHeightWindow, 800}, {1, 1, 1}}; 
    scene.add (*(Object*)&sphere);
    scene.add (*(Object*)&light);
                          
    Button buttonOffOn = {true, {75, 50},   {75, 75}, {1, 1, 1, kInitialColorAlpha}};
    Button buttonUp    = {true, {850, 150}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};
    Button buttonDown  = {true, {850, 250}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};
    Button buttonLeft  = {true, {800, 200}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};
    Button buttonRight = {true, {900, 200}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};

    Button buttonLight1 = {true, {790, 50}, {70, 70}, {1, 1, 1, kInitialColorAlpha}};
    Button buttonLight2 = {true, {890, 50}, {70, 70}, {1, 1, 1, kInitialColorAlpha}};
    
    Button buttonSphereSubR = {true, {820, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha - kInitialShiftAlpha}};
    Button buttonSphereAddR = {true, {880, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha + kInitialShiftAlpha}};
    Button buttonSphereSubG = {true, {820, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha - kInitialShiftAlpha}};
    Button buttonSphereAddG = {true, {880, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha + kInitialShiftAlpha}};
    Button buttonSphereSubB = {true, {820, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha - kInitialShiftAlpha}};
    Button buttonSphereAddB = {true, {880, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha + kInitialShiftAlpha}};

    Button buttonLightSubR = {true, {70, 350},  {50, 50}, {1, 0, 0, kInitialColorAlpha - kInitialShiftAlpha}};
    Button buttonLightAddR = {true, {130, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha + kInitialShiftAlpha}};
    Button buttonLightSubG = {true, {70, 410},  {50, 50}, {0, 1, 0, kInitialColorAlpha - kInitialShiftAlpha}};
    Button buttonLightAddG = {true, {130, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha + kInitialShiftAlpha}};
    Button buttonLightSubB = {true, {70, 470},  {50, 50}, {0, 0, 1, kInitialColorAlpha - kInitialShiftAlpha}};
    Button buttonLightAddB = {true, {130, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha + kInitialShiftAlpha}};

    ActionOffOn     bOffOnAct = {sphere}; buttonOffOn.addAction (&bOffOnAct);
    ActionMoveUp    bUpAct    = {light};  buttonUp.addAction    (&bUpAct);
    ActionMoveDown  bDownAct  = {light};  buttonDown.addAction  (&bDownAct);
    ActionMoveLeft  bLeftAct  = {light};  buttonLeft.addAction  (&bLeftAct);
    ActionMoveRight bRightAct = {light};  buttonRight.addAction (&bRightAct);

    ActionColorAddR actSphereAddR = {sphere}; buttonSphereAddR.addAction (&actSphereAddR);
    ActionColorSubR actSphereSubR = {sphere}; buttonSphereSubR.addAction (&actSphereSubR);
    ActionColorAddG actSphereAddG = {sphere}; buttonSphereAddG.addAction (&actSphereAddG);
    ActionColorSubG actSphereSubG = {sphere}; buttonSphereSubG.addAction (&actSphereSubG);
    ActionColorAddB actSphereAddB = {sphere}; buttonSphereAddB.addAction (&actSphereAddB);
    ActionColorSubB actSphereSubB = {sphere}; buttonSphereSubB.addAction (&actSphereSubB);

    ActionColorAddR actLightAddR = {light}; buttonLightAddR.addAction (&actLightAddR);
    ActionColorSubR actLightSubR = {light}; buttonLightSubR.addAction (&actLightSubR);
    ActionColorAddG actLightAddG = {light}; buttonLightAddG.addAction (&actLightAddG);
    ActionColorSubG actLightSubG = {light}; buttonLightSubG.addAction (&actLightSubG);
    ActionColorAddB actLightAddB = {light}; buttonLightAddB.addAction (&actLightAddB);
    ActionColorSubB actLightSubB = {light}; buttonLightSubB.addAction (&actLightSubB);

    scene.add (*(Object*)&buttonOffOn);
    scene.add (*(Object*)&buttonUp);
    scene.add (*(Object*)&buttonLeft);
    scene.add (*(Object*)&buttonDown);
    scene.add (*(Object*)&buttonRight);

    scene.add (*(Object*)&buttonLight1);
    scene.add (*(Object*)&buttonLight2);

    scene.add (*(Object*)&buttonSphereAddR);
    scene.add (*(Object*)&buttonSphereSubR);
    scene.add (*(Object*)&buttonSphereAddG);
    scene.add (*(Object*)&buttonSphereSubG);
    scene.add (*(Object*)&buttonSphereAddB);
    scene.add (*(Object*)&buttonSphereSubB);

    scene.add (*(Object*)&buttonLightAddR);
    scene.add (*(Object*)&buttonLightSubR);
    scene.add (*(Object*)&buttonLightAddG);
    scene.add (*(Object*)&buttonLightSubG);
    scene.add (*(Object*)&buttonLightAddB);
    scene.add (*(Object*)&buttonLightSubB);

    ActiveScene (scene, ctx);
}
