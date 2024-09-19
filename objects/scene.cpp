#include "scene.h"

// Scene::Scene (bool init_isDraw)
//     : isDraw(init_isDraw)
// {}

void Scene::add (Object& object)
{
    objects.push_back(&object);
    object.scene = this;
}

ObjectType Scene::type () const 
{
    return ObjectTypeScene;
}         

void Scene::setCoordShift (coord_t x, coord_t y, coord_t z)
{
}

void Scene::setColorShift (color_t r, color_t g, color_t b)
{
}

void Scene::draw (GraphicsCtx& ctx) const
{
    if (isDraw == 0) return;
    
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i]->isDraw)
        {
            objects[i]->draw(ctx);
        }
    }
    // DrawScene (*this, ctx); 
}
