#include "testSimple3D.h"

const int kLightZ             = 1000;
const int kLightIntervalTest  = 1000;
const int kSpeedSphereTest    = 250;

void TestSphere3D (GraphicsCtx& ctx, Scene& scene)
{
    ((Light*)scene.objects[2])->coord = {-kLightIntervalTest, -kLightIntervalTest, kLightZ};

    int temp = kSpeedSphereTest;

    for (; ((Light*)scene.objects[2])->coord.x < kLightIntervalTest; ((Light*)scene.objects[2])->coord.x += temp)
    {
        CleanWindow (ctx);

        scene.draw (ctx);

        DisplayWindow(ctx);
    }

    for (; ((Light*)scene.objects[2])->coord.y < kLightIntervalTest; ((Light*)scene.objects[2])->coord.y += temp)
    {
        CleanWindow (ctx);

        scene.draw (ctx);

        DisplayWindow(ctx);
    }

    for (; ((Light*)scene.objects[2])->coord.x >- kLightIntervalTest; ((Light*)scene.objects[2])->coord.x -= temp)
    {
        CleanWindow (ctx);

        scene.draw (ctx);

        DisplayWindow(ctx);
    }

    for (; ((Light*)scene.objects[2])->coord.y >- kLightIntervalTest; ((Light*)scene.objects[2])->coord.y -= temp)
    {
        CleanWindow (ctx);

        scene.draw (ctx);

        DisplayWindow(ctx);
    }
}

void TestSimple3D (GraphicsCtx& ctx)
{
    Scene scene {};

    Sphere sphere    {true,  250, {0, 1, 1}, {0, 0.005, 0.005}};
    
    Light  lightStat {false, {300, -400, 800}, {0, 1, 1}}; 
    Light  lightDyn  {false, {0, 0, 0},        {0, 1, 1}}; 

    scene.add (*(Object*)&sphere);     
    scene.add (*(Object*)&lightStat);
    scene.add (*(Object*)&lightDyn);

    TestSphere3D (ctx, scene);
}