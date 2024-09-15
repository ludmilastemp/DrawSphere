#ifndef STL_BUTTON
#define STL_BUTTON

#include "object.h"
#include "actions.h"
#include "../GrLib/GrLibCtx.h"
#include "../vectors/vectorDec.h"

class Button : public Object
{
public:
    VectorDec corner;
    VectorDec size;

    Object& object;
    void (*actionFunc) (Object* object); // typedef

    Button (             const VectorDec& corner, const VectorDec& size, Object& object, void (*action) (Object* object));
    Button (bool isDraw, const VectorDec& corner, const VectorDec& size, Object& object, void (*action) (Object* object));
    
    void action ();

    virtual ObjectType type () const override;         
    virtual void       setCoordShift (coord_t x, coord_t y, coord_t z = 0) override; 
    virtual void       draw (GraphicsCtx& ctx) const override;                              
};

bool IsButtonPressed (const sf::Vector2i& pos, const Button& button);

#endif /* STL_BUTTON */