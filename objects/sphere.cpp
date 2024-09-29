#include "sphere.h"

#include "../GrLib/GrLibCtx.h"
#include <math.h>

const Vector3D kViewer  = {0, 0, 300};

void DrawSphere3D (const Sphere& sphere, GraphicsCtx& ctx, Scene& scene);
Color ComputeLightColor (const Sphere& sphere, const Vector3D& point, const Light& light);

/**************************************************************************/

Sphere::Sphere (double init_radius, Color init_materiaColor, Color init_ambientColor, double init_MAGIC)
    : Object(1), radius(init_radius), materiaColor (init_materiaColor), ambientColor(init_ambientColor), MAGIC(init_MAGIC)
{}

Sphere::Sphere (bool isDraw, double init_radius, Color init_materiaColor, Color init_ambientColor, double init_MAGIC)
    : Object(isDraw), radius(init_radius), materiaColor (init_materiaColor), ambientColor(init_ambientColor), MAGIC(init_MAGIC)
{}

/**************************************************************************/

ObjectType Sphere::type () const 
{
    return ObjectTypeSphere;
}         

void Sphere::setCoordShift (coord_t x, coord_t y, coord_t z)
{
    // corner.x += x;
    // corner.y += y;
}

void Sphere::setColorShift (color_t r, color_t g, color_t b)
{
    if (0 <= materiaColor.r + r && materiaColor.r + r <= 1) materiaColor.r += r;
    if (0 <= materiaColor.g + g && materiaColor.g + g <= 1) materiaColor.g += g;
    if (0 <= materiaColor.b + b && materiaColor.b + b <= 1) materiaColor.b += b;
}

void Sphere::draw (GraphicsCtx& ctx) const
{
    DrawSphere3D (*this, ctx, *(this->scene)); 
}

/**************************************************************************/

Color ComputeLightColor (const Sphere& sphere, const Vector3D& point, const Light& light)
{
    double diffuseCoef = CalculateCosAngle (point, light.coord - point);
    Vector3D otr       = ReflectVector     (light.coord - point, point);
    double glareCoef   = CalculateCosAngle (otr, kViewer - point);

    if (diffuseCoef < 0) diffuseCoef = 0;
    if (glareCoef   < 0) glareCoef = 0;

    const int kLightCircleSize = 7; // от 1 до 10

    glareCoef   = pow (glareCoef,   15);
    diffuseCoef = pow (diffuseCoef, 11 - kLightCircleSize);

    Color color = sphere.materiaColor * sphere.ambientColor                        + 
                  sphere.materiaColor * light.color * (sphere.MAGIC + diffuseCoef) + 
                                        light.color * glareCoef;

    return color;
}

void DrawSphere3D (const Sphere& sphere, GraphicsCtx& ctx, Scene& scene)
{
    sf::VertexArray points(sf::Points, kHeightWindow * 2);

    for (int i = -kWidthWindow; i < kWidthWindow; i++)
    {
        for (int j = -kHeightWindow; j < kHeightWindow; j++)
        {
            int r1 = i * i + j * j;
            double z = sqrt (sphere.radius * sphere.radius - r1);

            Vector3D point {i, j, z};

            if (r1 <= sphere.radius * sphere.radius)
            {   
                Color color = sphere.materiaColor * sphere.ambientColor;

                for (size_t q = 0; q < scene.objects.size(); q++)
                {
                    if (scene.objects[q]->type() == ObjectTypeLight)
                    {   
                        color = color + ComputeLightColor (sphere, point, *(Light*)scene.objects[q]);
                    }
                }

                color.clamp();
                color = color * 255;

                points[(size_t)j + kHeightWindow] = 
                    sf::Vertex(sf::Vector2f(i + kWidthWindow, j + kHeightWindow), 
                                sf::Color (color.r, color.g, color.b));
            }
        }
        ctx.window.draw(points);
    } 
}

/**************************************************************************/
