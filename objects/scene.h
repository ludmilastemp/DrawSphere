#ifndef STL_SCENE
#define STL_SCENE

#include "../GrLib/GrLibCtx.h"
#include <vector>
#include "object.h"

class Scene : public Object
{
public:
    std::vector <Object*> objects;

    Scene () : Object(1) {}

    void add (Object& object);

    virtual ObjectType type () const override;         
    virtual void setCoordShift (coord_t x, coord_t y, coord_t z = 0) override;
    virtual void setColorShift (color_t r, color_t g, color_t b)     override;
    virtual void draw (GraphicsCtx& ctx) const override;
};

#endif /* STL_SCENE */