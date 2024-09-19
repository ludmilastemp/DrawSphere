#include "lightManager.h"

#include <cassert>

/**************************************************************************/

LightManager::LightManager ()
    : Object(1), activeScene (nullptr)
{}

/**************************************************************************/

ObjectType LightManager::type () const 
{
    return ObjectTypeLightManager;
}         

void LightManager::setCoordShift (coord_t x, coord_t y, coord_t z)
{}

void LightManager::setColorShift (color_t r, color_t g, color_t b)
{}

void LightManager::draw (GraphicsCtx& ctx) const 
{
    if (activeScene != nullptr)
        activeScene->draw(ctx);
}

/**************************************************************************/

void LightManager::addScene (Scene& scene)
{
    scenes.push_back(&scene);
}

void LightManager::activate (Scene& scene)
{
    deActivate ();
    scene.isDraw = 1;
    activeScene = &scene;
}

void LightManager::deActivate ()
{
    if (activeScene != nullptr)
        activeScene->isDraw = 0;
    activeScene = nullptr;
}

/**************************************************************************/
