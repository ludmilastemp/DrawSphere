#include "actions.h"
#include <assert.h>

const int kSpeedButtonControl = 50;

void OffOn (Object* object)
{
    assert (object);

    if (object->isDraw) 
        object->isDraw = false; 
    else 
        object->isDraw = true;
}

void MoveUp (Object* object)
{
    assert (object);

    object->setCoordShift (0, kSpeedButtonControl);    
}

void MoveDown (Object* object)
{
    assert (object);

    object->setCoordShift (0, -kSpeedButtonControl);    
}

void MoveLeft (Object* object)
{
    assert (object);

    object->setCoordShift (-kSpeedButtonControl, 0);    
}

void MoveRight (Object* object)
{
    assert (object);

    object->setCoordShift (kSpeedButtonControl, 0);    
}