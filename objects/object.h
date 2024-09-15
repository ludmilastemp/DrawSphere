#ifndef STL_OBJECT
#define STL_OBJECT

#include "../GrLib/GrLibCtx.h"
#include <vector>

using coord_t = int; // осторожно, объявлено в двух местах

enum ObjectType // enum class
{
    ObjectTypeButton,
    ObjectTypeLight,
    ObjectTypeSphere,
};

class Object;

class Scene
{
public:
    bool isDraw;
    std::vector <Object*> objects;

    Scene (bool isDraw = 0);

    void add (Object& object);
};

class Object
{
public:
    bool isDraw;
    // std::vector <Object*>* scene;
    Scene* scene;

    Object (bool isDraw = 0);
    ~Object (){}

/// + метод который меняет сцену

    virtual ObjectType type () const = 0;
    virtual void       setCoordShift (coord_t x, coord_t y, coord_t z = 0) = 0;
    virtual void       draw (GraphicsCtx& ctx) const = 0;
};

void DrawScene (Scene& scene, GraphicsCtx& ctx);


/*
class Scene
{
    add()...
}
*/

#endif /* STL_OBJECT */