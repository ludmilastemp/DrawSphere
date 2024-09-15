#include "object.h"

Object::Object (bool init_isDraw)
    : isDraw(init_isDraw)
{}

Scene::Scene (bool init_isDraw)
    : isDraw(init_isDraw)
{}

void DrawScene (Scene& scene, GraphicsCtx& ctx)
{
    for (int i = 0; i < scene.objects.size(); i++)
    {
        if (scene.objects[i]->isDraw)
        {
            scene.objects[i]->draw(ctx);
        }
    }
}

void Scene::add (Object& object)
{
    objects.push_back(&object);
    object.scene = this;
}