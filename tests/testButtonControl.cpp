#include "testButtonControl.h"
#include <chrono>

const double kColorChangeSpeed = 0.05;
const double kInitialColorAlpha = 0.15;
const double kInitialShiftAlpha = 0.03;

void ActiveScene (Scene& scene, GraphicsCtx& ctx);
void ButtonManager (Button& button, GraphicsCtx& ctx);

void ActiveScene (Scene& scene, GraphicsCtx& ctx) 
{
    for (size_t i = 0; i < scene.objects.size(); i++)
    {
        switch (scene.objects[i]->type())
        {
            case (ObjectTypeButton):
            {
                Button& button = *(Button*)(scene.objects[i]);
                ButtonManager (button, ctx);
                break;
            }
            case (ObjectTypeLightManager):
            {
                LightManager& lightManager = *(LightManager*)(scene.objects[i]);
                if (lightManager.activeScene != nullptr)
                    ActiveScene (*lightManager.activeScene, ctx);
                break;
            }
            case (ObjectTypeLight):
            case (ObjectTypeSphere):
            case (ObjectTypeScene):
            default: 
                ;
        }
    }
}

void ButtonManager (Button& button, GraphicsCtx& ctx)
{
    sf::Vector2i pos = sf::Mouse::getPosition(ctx.window);
    if (button.isDraw == 1 && IsButton (pos, button))
    {
        if (ctx.event.type == sf::Event::MouseButtonPressed &&
            ctx.event.mouseButton.button == sf::Mouse::Left)
        {
            for (size_t act = 0; act < button.actions.size(); act++)
            {
                (*button.actions[act])();
            }
        }
        if (button.color.a + kColorChangeSpeed < 1) 
            button.color.a += kColorChangeSpeed;
    }
    else 
    {
        if (button.color.a - kColorChangeSpeed >= kInitialColorAlpha) 
            button.color.a -= kColorChangeSpeed;
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

    LightManager lightManager {};

    const int nLight = 2;
    Light lights[nLight] = {
        {false, {50,  -150, 800}, {0, 1, 1}},   // бирюзовый
        {false, {500, 150,  800}, {1, 0, 1}}};  // фиолетовый

    mainScene.add (*(Object*)&sphere);
    mainScene.add (*(Object*)&lightManager);
    for (int iLight = 0; iLight < nLight; iLight++)
        mainScene.add (*(Object*)&lights[iLight]);
                          
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
 * Создать сцены для источников света
 */
    Scene scenesLight[nLight] = {{}, {}};
    for (int iLight = 0; iLight < nLight; iLight++)
        lightManager.addScene (scenesLight[iLight]);

    Button buttonsLight[nLight] = {
        {true, {790, 50}, {70, 70}, {1, 1, 1, kInitialColorAlpha}},
        {true, {890, 50}, {70, 70}, {1, 1, 1, kInitialColorAlpha}}};

    ActionActivateLightManager actButtonsLight[nLight] = { // ctor по умолчанию
        {lightManager, scenesLight[0]},
        {lightManager, scenesLight[1]}}; 
    
    for (int iLight = 0; iLight < nLight; iLight++)
    {
        buttonsLight[iLight].addAction (&actButtonsLight[iLight]);
        mainScene.add (*(Object*)&buttonsLight[iLight]);
    }

/*
 * Создать кнопки для изменения цвета источников света
 */
    Button buttonLightSubR[nLight] = {
        {true, {820, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha}},
        {true, {820, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha}}};
    Button buttonLightAddR[nLight] = {
        {true, {880, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha + kInitialShiftAlpha}},
        {true, {880, 350}, {50, 50}, {1, 0, 0, kInitialColorAlpha + kInitialShiftAlpha}}};
    Button buttonLightSubG[nLight] = {
        {true, {820, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha}},
        {true, {820, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha}}};
    Button buttonLightAddG[nLight] = {
        {true, {880, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha + kInitialShiftAlpha}},
        {true, {880, 410}, {50, 50}, {0, 1, 0, kInitialColorAlpha + kInitialShiftAlpha}}};
    Button buttonLightSubB[nLight] = {
        {true, {820, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha}},
        {true, {820, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha}}};
    Button buttonLightAddB[nLight] = {
        {true, {880, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha + kInitialShiftAlpha}},
        {true, {880, 470}, {50, 50}, {0, 0, 1, kInitialColorAlpha + kInitialShiftAlpha}}};

/*
 * Создать action для кнопки для изменения цвета источников света
 */
    ActionColorAddR actLightAddR[nLight] = {{lights[0]}, {lights[1]}};
    ActionColorSubR actLightSubR[nLight] = {{lights[0]}, {lights[1]}};
    ActionColorAddG actLightAddG[nLight] = {{lights[0]}, {lights[1]}};
    ActionColorSubG actLightSubG[nLight] = {{lights[0]}, {lights[1]}};
    ActionColorAddB actLightAddB[nLight] = {{lights[0]}, {lights[1]}};
    ActionColorSubB actLightSubB[nLight] = {{lights[0]}, {lights[1]}};

    for (int iLight = 0; iLight < nLight; iLight++) 
    {
        /*
        * Добавить action для кнопки для изменения цвета источников света
        */

        buttonLightAddR[iLight].addAction (&actLightAddR[iLight]);
        buttonLightSubR[iLight].addAction (&actLightSubR[iLight]);
        buttonLightAddG[iLight].addAction (&actLightAddG[iLight]);
        buttonLightSubG[iLight].addAction (&actLightSubG[iLight]);
        buttonLightAddB[iLight].addAction (&actLightAddB[iLight]);
        buttonLightSubB[iLight].addAction (&actLightSubB[iLight]);

        /*
        * Добавить кнопки в сцену
        */

        scenesLight[iLight].add (*(Object*)&buttonLightAddR[iLight]);
        scenesLight[iLight].add (*(Object*)&buttonLightSubR[iLight]);
        scenesLight[iLight].add (*(Object*)&buttonLightAddG[iLight]);
        scenesLight[iLight].add (*(Object*)&buttonLightSubG[iLight]);
        scenesLight[iLight].add (*(Object*)&buttonLightAddB[iLight]);
        scenesLight[iLight].add (*(Object*)&buttonLightSubB[iLight]);
    }

/*
 * Создать кнопки для изменения координат источников света
 */
    Button buttonLightUp[nLight] = {
        {true, {850, 150}, {50, 50}, {1, 1, 1, kInitialColorAlpha}},
        {true, {850, 150}, {50, 50}, {1, 1, 1, kInitialColorAlpha}}};
    Button buttonLightDown[nLight] = {
        {true, {850, 250}, {50, 50}, {1, 1, 1, kInitialColorAlpha}},
        {true, {850, 250}, {50, 50}, {1, 1, 1, kInitialColorAlpha}}};
    Button buttonLightLeft[nLight] = {
        {true, {800, 200}, {50, 50}, {1, 1, 1, kInitialColorAlpha}},
        {true, {800, 200}, {50, 50}, {1, 1, 1, kInitialColorAlpha}}};
    Button buttonLightRight[nLight] = {
        {true, {900, 200}, {50, 50}, {1, 1, 1, kInitialColorAlpha}},
        {true, {900, 200}, {50, 50}, {1, 1, 1, kInitialColorAlpha}}};

/*
 * Создать action для кнопки для изменения координат источников света
 */
    ActionMoveUp actbLightUp[nLight]       = {{lights[0]}, {lights[1]}};
    ActionMoveDown actbLightDown[nLight]   = {{lights[0]}, {lights[1]}};
    ActionMoveLeft actbLightLeft[nLight]   = {{lights[0]}, {lights[1]}};
    ActionMoveRight actbLightRight[nLight] = {{lights[0]}, {lights[1]}};

    for (int iLight = 0; iLight < nLight; iLight++) 
    {
        /*
        * Добавить action для кнопки для изменения координат источников света
        */

        buttonLightUp[iLight].addAction    (&actbLightUp[iLight]);
        buttonLightDown[iLight].addAction  (&actbLightDown[iLight]);
        buttonLightLeft[iLight].addAction  (&actbLightLeft[iLight]);
        buttonLightRight[iLight].addAction (&actbLightRight[iLight]);

        /*
        * Добавить кнопки в сцену
        */

        scenesLight[iLight].add (*(Object*)&buttonLightUp[iLight]);
        scenesLight[iLight].add (*(Object*)&buttonLightLeft[iLight]);
        scenesLight[iLight].add (*(Object*)&buttonLightDown[iLight]);
        scenesLight[iLight].add (*(Object*)&buttonLightRight[iLight]);
    }

/*
 * Создать текст
 */
    sf::Font font;
    font.loadFromFile("/media/ludmila/1308FE611F0B7EEB/Windows/Fonts/arial.ttf");
    
    sf::Text textOn("On", font);
    textOn.setCharacterSize(20);
    textOn.setFillColor(sf::Color::White);
    textOn.setPosition(100, 60);

    sf::Text textOff("Off", font);
    textOff.setCharacterSize(20);
    textOff.setFillColor(sf::Color::White);
    textOff.setPosition(99, 85);
        
    // 0.002 секунды
    // printf ("%lg\n", buttonLightUp[0].color.a);

    while (true)
    {
        while (ctx.window.pollEvent(ctx.event))
        {
            if (ctx.event.type == sf::Event::Closed)
            {
                // printf ("%lg\n", buttonLightUp[0].color.a);
                return;
            }
        ActiveScene (mainScene, ctx);
        }
        
        CleanWindow (ctx);
        

        mainScene.draw (ctx);
        ctx.window.draw(textOn);
        ctx.window.draw(textOff);

        DisplayWindow(ctx);
    }

}
