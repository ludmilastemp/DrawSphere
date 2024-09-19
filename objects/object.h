#ifndef STL_OBJECT
#define STL_OBJECT

#include "scene.h"
#include "../color.h"

using coord_t = int; 

// struct Interaction
// {
//     enum InteractionType
//     {
//         MouseEntered, 
//         MouseLeft,
//         MousePressed,
//     };

//     InteractionType type;
//     time_tt time;
// };

enum ObjectType // enum class
{
    ObjectTypeButton,
    ObjectTypeLight,
    ObjectTypeSphere,
};

// enum IsDraw 
// {

// }

class Object
{
public:
    bool isDraw;
    Scene* scene;

    Object (bool isDraw = 0);
    ~Object (){} /// virtual

/// + метод который меняет сцену

    virtual ObjectType type () const = 0;
    virtual void       setCoordShift (coord_t x, coord_t y, coord_t z = 0) = 0;
    virtual void       setColorShift (color_t r, color_t g, color_t b)     = 0;
    virtual void       draw (GraphicsCtx& ctx) const = 0;
};

#endif /* STL_OBJECT */