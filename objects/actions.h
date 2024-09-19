#ifndef STL_ACTIONS
#define STL_ACTIONS

#include "actionClass.h"
#include "object.h"
#include "lightManager.h"

const int kSpeedButtonControl = 50;
const double kSpeedColor = 0.1;

/**************************************************************************/

class ActionOffOn : public Action
{
public:
    Object& object;

    ActionOffOn (Object& init_object)
        : object(init_object)
    {}

    virtual void call () override
    {
        if (object.isDraw) 
            object.isDraw = false; 
        else 
            object.isDraw = true;
    };
};

class ActionMoveUp : public Action
{
public:
    Object& object;

    ActionMoveUp (Object& init_object)
        : object(init_object)
    {}

    virtual void call () override 
    {
        object.setCoordShift (0, kSpeedButtonControl);   
    };
};

class ActionMoveDown : public Action
{
public:
    Object& object;

    ActionMoveDown (Object& init_object)
        : object(init_object)
    {}

    virtual void call () override
    {
        object.setCoordShift (0, -kSpeedButtonControl);      
    };
}; 
   
class ActionMoveLeft : public Action
{
public:
    Object& object;

    ActionMoveLeft (Object& init_object)
        : object(init_object)
    {}

    virtual void call () override
    {
        object.setCoordShift (-kSpeedButtonControl, 0);  
    };
};

class ActionMoveRight : public Action
{
public:
    Object& object;

    ActionMoveRight (Object& init_object)
        : object(init_object)
    {}

    virtual void call () override
    {
        object.setCoordShift (kSpeedButtonControl, 0); 
    };
};

/**************************************************************************/

class ActionColorAddR : public Action
{
public:
    Object& object;

    ActionColorAddR (Object& init_object)
        : object(init_object)
    {}

    virtual void call () override
    {
        object.setColorShift (kSpeedColor, 0, 0); 
    };
};

class ActionColorSubR : public Action
{
public:
    Object& object;

    ActionColorSubR (Object& init_object)
        : object(init_object)
    {}

    virtual void call () override
    {
        object.setColorShift (-kSpeedColor, 0, 0); 
    };
};

class ActionColorAddG : public Action
{
public:
    Object& object;

    ActionColorAddG (Object& init_object)
        : object(init_object)
    {}

    virtual void call () override
    {
        object.setColorShift (0, kSpeedColor, 0); 
    };
};

class ActionColorSubG : public Action
{
public:
    Object& object;

    ActionColorSubG (Object& init_object)
        : object(init_object)
    {}

    virtual void call () override
    {
        object.setColorShift (0, -kSpeedColor, 0); 
    };
};

class ActionColorAddB : public Action
{
public:
    Object& object;

    ActionColorAddB (Object& init_object)
        : object(init_object)
    {}

    virtual void call () override
    {
        object.setColorShift (0, 0, kSpeedColor); 
    };
};

class ActionColorSubB : public Action
{
public:
    Object& object;

    ActionColorSubB (Object& init_object)
        : object(init_object)
    {}

    virtual void call () override
    {
        object.setColorShift (0, 0, -kSpeedColor); 
    };
};

/**************************************************************************/

class ActionActivateLightManager : public Action
{
public:
    LightManager& lightManager;
    Scene& scene;

    ActionActivateLightManager (LightManager& init_lightManager, Scene& init_scene)
        : lightManager(init_lightManager), scene(init_scene)
    {}

    virtual void call () override
    {
        if (lightManager.activeScene == &scene)
            lightManager.deActivate();
        else
            lightManager.activate(scene); 
    };
};

/**************************************************************************/

#endif /* STL_ACTIONS */