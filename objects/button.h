#ifndef STL_BUTTON
#define STL_BUTTON

#include "object.h"
#include "scene.h"
#include "actions.h"
#include "../GrLib/GrLibCtx.h"
#include "../vectors/vectorDec.h"

#include <assert.h>

class Button : public Object
{
public:
    VectorDec corner;
    VectorDec size;
    Color color;

    std::vector <Action*> actions; 

    Button ( /* enum */  const VectorDec& corner, const VectorDec& size, const Color& color);
    Button (bool isDraw, const VectorDec& corner, const VectorDec& size, const Color& color);
    
    void addAction (Action* action)
    {
        assert (action);
        actions.push_back (action);
    }

    virtual ObjectType type () const override;         
    virtual void setCoordShift (coord_t x, coord_t y, coord_t z = 0) override; 
    virtual void setColorShift (color_t r, color_t g, color_t b)     override;
    virtual void draw (GraphicsCtx& ctx) const override;                              
};

bool IsButton (const sf::Vector2i& pos, const Button& button);

#endif /* STL_BUTTON */