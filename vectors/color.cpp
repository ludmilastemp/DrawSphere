#include "color.h"

#include <stdio.h>
#include <math.h>
#include <assert.h>

/**************************************************************************/

Color::Color (color_t init_r, color_t init_g, color_t init_b) 
    : r(init_r), g(init_g), b(init_b)
{}

/**************************************************************************/

Color Color::operator+ (const Color& color2) const
{
    return Color {r + color2.r, g + color2.g, b + color2.b};
}

Color Color::operator- (const Color& color2) const
{
    return Color {r - color2.r, g - color2.g, b - color2.b};
}

Color Color::operator* (const Color& color2) const
{
    return Color {r * color2.r, g * color2.g, b * color2.b};
}

Color Color::operator* (const double mul) const
{
    return Color {r * mul, g * mul, b * mul};
}

Color Color::operator/ (const double mul) const
{
    return Color {r / mul, g / mul, b / mul};
}

Color Color::operator- () const
{
    return Color {-r, -g, -b};
}

/**************************************************************************/

void Color::clamp ()
{
    if (r > 1) r = 1;
    if (g > 1) g = 1;
    if (b > 1) b = 1;
}
/**************************************************************************/
