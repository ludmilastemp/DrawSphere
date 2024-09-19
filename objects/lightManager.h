#ifndef STL_LIGHTMANAGER
#define STL_LIGHTMANAGER

#include "object.h"
#include "scene.h"
#include "../GrLib/GrLibCtx.h"

class LightManager : public Object
{
public:
    std::vector <Scene*> scenes;

    Scene* activeScene;

    LightManager ();

    void addScene (Scene& scene);
    void activate (Scene& scene);
    void deActivate ();

    virtual ObjectType type () const override;         
    virtual void setCoordShift (coord_t x, coord_t y, coord_t z = 0) override;
    virtual void setColorShift (color_t r, color_t g, color_t b)     override;
    virtual void draw (GraphicsCtx& ctx) const override;
}; 

#endif /* STL_LIGHTMANAGER */