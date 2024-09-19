#include "button.h"


void DrawButton (const Button& button, GraphicsCtx& ctx);

/**************************************************************************/

Button::Button (const VectorDec& init_corner, const VectorDec& init_size, const Color& init_color)
    : Object(0), corner(init_corner), size(init_size), color(init_color)
{}

Button::Button (bool isDraw, const VectorDec& init_corner, const VectorDec& init_size, const Color& init_color)
    : Object(isDraw), corner(init_corner), size(init_size), color(init_color)
{}

/**************************************************************************/

ObjectType Button::type () const 
{
    return ObjectTypeButton;
}         

void Button::setCoordShift (coord_t x, coord_t y, coord_t z)
{
    corner.x += x;
    corner.y -= y;
}

void Button::setColorShift (color_t r, color_t g, color_t b)     
{
    if (0 <= color.r + r && color.r + r <= 1) color.r += r;
    if (0 <= color.g + g && color.g + g <= 1) color.g += g;
    if (0 <= color.b + b && color.b + b <= 1) color.b += b;
}

void Button::draw (GraphicsCtx& ctx) const
{
    DrawButton (*this, ctx); 
}

/**************************************************************************/

bool IsButton (const sf::Vector2i& pos, const Button& button)
{
    return 
        button.corner.x <= pos.x && 
                           pos.x <= button.corner.x + button.size.x &&
        button.corner.y <= pos.y && 
                           pos.y <= button.corner.y + button.size.y;

}

void DrawButton (const Button& button, GraphicsCtx& ctx)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(button.size.x, button.size.y));
    Color buttonColor = button.color * 255;
    rectangle.setFillColor(sf::Color (buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a));
    // rectangle.setOutlineThickness(5);
    rectangle.setPosition(button.corner.x, button.corner.y);
    ctx.window.draw(rectangle);
}

/**************************************************************************/
