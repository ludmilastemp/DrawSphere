#ifndef STL_LIGHT
#define STL_LIGHT

#include "object.h"
#include "../vectors/vector3D.h"
#include "../GrLib/GrLib.h"
#include "../color.h"

class Light : public Object
{
public:
    Vector3D coord;
    Color    color;

    Light (             const Vector3D& coord, const Color& color);
    Light (bool isDraw, const Vector3D& coord, const Color& color);

    virtual ObjectType type () const override;         
    virtual void setCoordShift (coord_t x, coord_t y, coord_t z = 0) override;
    virtual void setColorShift (color_t r, color_t g, color_t b)     override;
    virtual void draw (GraphicsCtx& ctx) const override;
}; 

#endif /* STL_LIGHT */