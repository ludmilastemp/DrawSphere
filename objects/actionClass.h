#ifndef STL_ACTIONSCLASS
#define STL_ACTIONSCLASS

enum ActionType
{
    ActionTypeOffOn,
    ActionTypeMoveUp,
    ActionTypeMoveDown,
    ActionTypeMoveLeft,
    ActionTypeMoveRight,
    ActionTypeColorAddR,
    ActionTypeColorSubR,
    ActionTypeColorAddG,
    ActionTypeColorSubG,
    ActionTypeColorAddB,
    ActionTypeColorSubB,
    ActionTypeActivateLightManager,
};

class Action // функтор
{
public:

    virtual ~Action () = default;

    void operator() ()
    {
        call();
    }

    virtual ActionType type() = 0;
    virtual void call() = 0;
};

/**************************************************************************/

#endif /* STL_ACTIONS */