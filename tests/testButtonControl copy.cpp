#include "testButtonControl.h"

const double kColorSpeed = 0.05;
const double kInitialColorAlpha = 0.15;
const double kInitialShiftAlpha = 0.03;

void ActiveScene (Scene& scene, GraphicsCtx& ctx, sf::Event& event)
{
    for (int i = 0; i < scene.objects.size(); i++)
    {
        switch (scene.objects[i]->type())
        {
            case (ObjectTypeButton):
            {
                Button& button = *(Button*)(scene.objects[i]);
                sf::Vector2i pos = sf::Mouse::getPosition(ctx.window);

                if (button.isDraw == 1 && IsButton (pos, button))
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
            case (ObjectTypeLightManager):
            {
                LightManager& lightManager = *(LightManager*)(scene.objects[i]);
                if (lightManager.activeScene != nullptr)
                    ActiveScene (*lightManager.activeScene, ctx, event);
            }
            case (ObjectTypeLight):
            case (ObjectTypeSphere):
            case (ObjectTypeScene):
            default: 
                ;
        }
    }
}

void TestButtonControl (GraphicsCtx& ctx)
{
/*
 * Создать главную сцену
 */
    Scene mainScene {};

/*
 * Создать и добавить главные объекты
 */
    Sphere sphere {true,  250, {1, 1, 1}, {0.005, 0.005, 0.005}};
    Light  light1  {false, {500, 150,  800}, {1, 0, 1}}; // фиол
    Light  light2  {false, {50,  -150, 800}, {0, 1, 1}}; // бир
    LightManager  lightManager {};

    mainScene.add (*(Object*)&sphere);
    mainScene.add (*(Object*)&light1);
    mainScene.add (*(Object*)&light2);
    mainScene.add (*(Object*)&lightManager);
                          
/*
 * Кнопка: Включить/выключить отрисовку сферу
 */
    Button buttonOffOn = {true, {75, 50},   {75, 75}, {1, 1, 1, kInitialColorAlpha}};
    ActionOffOn     actButtonOffOn = {sphere}; buttonOffOn.addAction (&actButtonOffOn);
    mainScene.add (*(Object*)&buttonOffOn);

/*
 * Кнопка: Поменять цвет сферы
 */
    Button buttonSphereSubR = {true, {70, 350},  {50, 50}, {1, 0, 0, kInitialColorAlpha}};
    Button buttonSphereAddR = {true, {130, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha + kInitialShiftAlpha}};
    Button buttonSphereSubG = {true, {70, 410},  {50, 50}, {0, 1, 0, kInitialColorAlpha}};
    Button buttonSphereAddG = {true, {130, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha + kInitialShiftAlpha}};
    Button buttonSphereSubB = {true, {70, 470},  {50, 50}, {0, 0, 1, kInitialColorAlpha}};
    Button buttonSphereAddB = {true, {130, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha + kInitialShiftAlpha}};

    ActionColorAddR actSphereAddR = {sphere}; buttonSphereAddR.addAction (&actSphereAddR);
    ActionColorSubR actSphereSubR = {sphere}; buttonSphereSubR.addAction (&actSphereSubR);
    ActionColorAddG actSphereAddG = {sphere}; buttonSphereAddG.addAction (&actSphereAddG);
    ActionColorSubG actSphereSubG = {sphere}; buttonSphereSubG.addAction (&actSphereSubG);
    ActionColorAddB actSphereAddB = {sphere}; buttonSphereAddB.addAction (&actSphereAddB);
    ActionColorSubB actSphereSubB = {sphere}; buttonSphereSubB.addAction (&actSphereSubB);

    mainScene.add (*(Object*)&buttonSphereAddR);
    mainScene.add (*(Object*)&buttonSphereSubR);
    mainScene.add (*(Object*)&buttonSphereAddG);
    mainScene.add (*(Object*)&buttonSphereSubG);
    mainScene.add (*(Object*)&buttonSphereAddB);
    mainScene.add (*(Object*)&buttonSphereSubB);

/*
 * Создать сцену для первого источника света
 */
    Scene sceneLight1 {};
    lightManager.addScene (sceneLight1);

    Button buttonLight1 = {true, {790, 50}, {70, 70}, {1, 1, 1, kInitialColorAlpha}};
    // Button buttonLight2 = {true, {890, 50}, {70, 70}, {1, 1, 1, kInitialColorAlpha}};
    ActionActivateLightManager bLight1 = {lightManager, sceneLight1}; buttonLight1.addAction (&bLight1);
    
    mainScene.add (*(Object*)&buttonLight1);

/*
 * Кнопка: Поменять цвет первого источника света
 */
    Button buttonLight1SubR = {true, {820, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha}};
    Button buttonLight1AddR = {true, {880, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha + kInitialShiftAlpha}};
    Button buttonLight1SubG = {true, {820, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha}};
    Button buttonLight1AddG = {true, {880, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha + kInitialShiftAlpha}};
    Button buttonLight1SubB = {true, {820, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha}};
    Button buttonLight1AddB = {true, {880, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha + kInitialShiftAlpha}};

    ActionColorAddR actLigh1tAddR = {light1}; buttonLight1AddR.addAction (&actLigh1tAddR);
    ActionColorSubR actLigh1tSubR = {light1}; buttonLight1SubR.addAction (&actLigh1tSubR);
    ActionColorAddG actLigh1tAddG = {light1}; buttonLight1AddG.addAction (&actLigh1tAddG);
    ActionColorSubG actLigh1tSubG = {light1}; buttonLight1SubG.addAction (&actLigh1tSubG);
    ActionColorAddB actLigh1tAddB = {light1}; buttonLight1AddB.addAction (&actLigh1tAddB);
    ActionColorSubB actLigh1tSubB = {light1}; buttonLight1SubB.addAction (&actLigh1tSubB);

    sceneLight1.add (*(Object*)&buttonLight1AddR);
    sceneLight1.add (*(Object*)&buttonLight1SubR);
    sceneLight1.add (*(Object*)&buttonLight1AddG);
    sceneLight1.add (*(Object*)&buttonLight1SubG);
    sceneLight1.add (*(Object*)&buttonLight1AddB);
    sceneLight1.add (*(Object*)&buttonLight1SubB);

/*
 * Кнопка: Поменять координаты лампы первого источника света
 */
    Button buttonLight1Up    = {true, {850, 150}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};
    Button buttonLight1Down  = {true, {850, 250}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};
    Button buttonLight1Left  = {true, {800, 200}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};
    Button buttonLight1Right = {true, {900, 200}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};

    ActionMoveUp    actbLight1Up   = {light1};  buttonLight1Up.addAction    (&actbLight1Up);
    ActionMoveDown  actbLight1Down = {light1};  buttonLight1Down.addAction  (&actbLight1Down);
    ActionMoveLeft  actbLight1Left = {light1};  buttonLight1Left.addAction  (&actbLight1Left);
    ActionMoveRight actbLight1Right= {light1};  buttonLight1Right.addAction (&actbLight1Right);

    sceneLight1.add (*(Object*)&buttonLight1Up);
    sceneLight1.add (*(Object*)&buttonLight1Left);
    sceneLight1.add (*(Object*)&buttonLight1Down);
    sceneLight1.add (*(Object*)&buttonLight1Right);

/*
 * Создать сцену для второго источника света
 */
    Scene sceneLight2 {};
    lightManager.addScene (sceneLight2);

    Button buttonLight2 = {true, {890, 50}, {70, 70}, {1, 1, 1, kInitialColorAlpha}};
    ActionActivateLightManager bLight2 = {lightManager, sceneLight2}; buttonLight2.addAction (&bLight2);
    
    mainScene.add (*(Object*)&buttonLight2);

/*
 * Кнопка: Поменять цвет второго источника света
 */
    Button buttonLight2SubR = {true, {820, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha}};
    Button buttonLight2AddR = {true, {880, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha + kInitialShiftAlpha}};
    Button buttonLight2SubG = {true, {820, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha}};
    Button buttonLight2AddG = {true, {880, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha + kInitialShiftAlpha}};
    Button buttonLight2SubB = {true, {820, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha}};
    Button buttonLight2AddB = {true, {880, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha + kInitialShiftAlpha}};

    ActionColorAddR actLigh2tAddR = {light2}; buttonLight2AddR.addAction (&actLigh2tAddR);
    ActionColorSubR actLigh2tSubR = {light2}; buttonLight2SubR.addAction (&actLigh2tSubR);
    ActionColorAddG actLigh2tAddG = {light2}; buttonLight2AddG.addAction (&actLigh2tAddG);
    ActionColorSubG actLigh2tSubG = {light2}; buttonLight2SubG.addAction (&actLigh2tSubG);
    ActionColorAddB actLigh2tAddB = {light2}; buttonLight2AddB.addAction (&actLigh2tAddB);
    ActionColorSubB actLigh2tSubB = {light2}; buttonLight2SubB.addAction (&actLigh2tSubB);

    sceneLight2.add (*(Object*)&buttonLight2AddR);
    sceneLight2.add (*(Object*)&buttonLight2SubR);
    sceneLight2.add (*(Object*)&buttonLight2AddG);
    sceneLight2.add (*(Object*)&buttonLight2SubG);
    sceneLight2.add (*(Object*)&buttonLight2AddB);
    sceneLight2.add (*(Object*)&buttonLight2SubB);

/*
 * Кнопка: Поменять координаты лампы второго источника света
 */
    Button buttonLight2Up    = {true, {850, 150}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};
    Button buttonLight2Down  = {true, {850, 250}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};
    Button buttonLight2Left  = {true, {800, 200}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};
    Button buttonLight2Right = {true, {900, 200}, {50, 50}, {1, 1, 1, kInitialColorAlpha}};

    ActionMoveUp    actbLight2Up   = {light2};  buttonLight2Up.addAction    (&actbLight2Up);
    ActionMoveDown  actbLight2Down = {light2};  buttonLight2Down.addAction  (&actbLight2Down);
    ActionMoveLeft  actbLight2Left = {light2};  buttonLight2Left.addAction  (&actbLight2Left);
    ActionMoveRight actbLight2Right= {light2};  buttonLight2Right.addAction (&actbLight2Right);

    sceneLight2.add (*(Object*)&buttonLight2Up);
    sceneLight2.add (*(Object*)&buttonLight2Left);
    sceneLight2.add (*(Object*)&buttonLight2Down);
    sceneLight2.add (*(Object*)&buttonLight2Right);

    while (true)
    {
        sf::Event event;
        while (ctx.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                return;
            }
            
            // sf::Vector2i pos = sf::Mouse::getPosition(ctx.window);
            
            ActiveScene (mainScene, ctx, event);
        }
        
        CleanWindow (ctx);

        mainScene.draw (ctx);

        DisplayWindow(ctx);
    }

}
