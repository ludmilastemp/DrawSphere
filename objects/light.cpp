#include "light.h"

#include "../GrLib/GrLibCtx.h"

Color ComputeLightColor (const Vector3D& point, const Vector3D& light);
void DrawLight3D (const Vector3D& light, GraphicsCtx& ctx, std::vector <Object*>& scene);
void TestLight3D (GraphicsCtx& ctx, std::vector <Object*>& scene);

/**************************************************************************/

Light::Light (const Vector3D& init_coord, const Color& init_color)
    : Object(0), coord(init_coord), color(init_color)
{}

Light::Light (bool isDraw, const Vector3D& init_coord, const Color& init_color)
    : Object(isDraw), coord(init_coord), color(init_color)
{}

/**************************************************************************/

ObjectType Light::type () const 
{
    return ObjectTypeLight;
}         

void Light::setCoordShift (coord_t x, coord_t y, coord_t z)
{
    coord.x += x;
    coord.y -= y;
}

void Light::setColorShift (color_t r, color_t g, color_t b)
{
    if (0 <= color.r + r && color.r + r <= 1) color.r += r;
    if (0 <= color.g + g && color.g + g <= 1) color.g += g;
    if (0 <= color.b + b && color.b + b <= 1) color.b += b;
}

void Light::draw (GraphicsCtx& ctx) const
{
    ;
}

/**************************************************************************/
