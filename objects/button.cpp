#include "button.h"


void DrawButton (const Button& button, GraphicsCtx& ctx);

/**************************************************************************/

Button::Button (const VectorDec& init_corner, const VectorDec& init_size, Object& init_object, void (*init_action) (Object* object))
    : Object(0), corner(init_corner), size(init_size), object(init_object), actionFunc(init_action)
{}

Button::Button (bool isDraw, const VectorDec& init_corner, const VectorDec& init_size, Object& init_object, void (*init_action) (Object* object))
    : Object(isDraw), corner(init_corner), size(init_size), object(init_object), actionFunc(init_action)
{}

/**************************************************************************/

void Button::action () 
{
    actionFunc(&object);
}         

ObjectType Button::type () const 
{
    return ObjectTypeButton;
}         

void Button::setCoordShift (coord_t x, coord_t y, coord_t z)
{
    corner.x += x;
    corner.y -= y;
}

void Button::draw (GraphicsCtx& ctx) const
{
    DrawButton (*this, ctx); 
}

/**************************************************************************/

bool IsButtonPressed (const sf::Vector2i& pos, const Button& button)
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
    rectangle.setOutlineColor(sf::Color::Green);
    // rectangle.setOutlineThickness(5);
    rectangle.setPosition(button.corner.x, button.corner.y);
    ctx.window.draw(rectangle);
}

/**************************************************************************/
