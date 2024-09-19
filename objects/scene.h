#ifndef STL_SCENE
#define STL_SCENE

#include "../GrLib/GrLibCtx.h"
#include <vector>

class Object;

class Scene
{
public:
    bool isDraw;
    std::vector <Object*> objects;

    Scene (bool isDraw = 0);

    void add (Object& object);
};

void DrawScene (Scene& scene, GraphicsCtx& ctx);

#endif /* STL_SCENE */