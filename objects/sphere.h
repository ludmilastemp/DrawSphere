#ifndef STL_SPHERE
#define STL_SPHERE

#include "object.h"
#include "../vectors/vector3D.h"
#include "../GrLib/GrLib.h"
#include "light.h"

class Sphere : public Object
{
public:
    // VectorDec center;
    double radius;
    Color materiaColor;
    Color ambientColor;
    double MAGIC;

    Sphere (             double radius, Color materiaColor, Color ambientColor, double MAGIC = 0.03);
    Sphere (bool isDraw, double radius, Color materiaColor, Color ambientColor, double MAGIC = 0.03);

    virtual ObjectType type () const override;         
    virtual void setCoordShift (coord_t x, coord_t y, coord_t z = 0) override;
    virtual void setColorShift (color_t r, color_t g, color_t b)     override;
    virtual void draw (GraphicsCtx& ctx) const override;
}; 

#endif /* STL_SPHERE */