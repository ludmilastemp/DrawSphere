#include "vectorDec.h"

/**************************************************************************/

VectorDec::VectorDec (int x, int y) 
    : x_(x), y_(y)
{}

VectorDec::VectorDec (const VectorDec& vDec) 
    : x_(vDec.x_), y_(vDec.y_)
{}

/**************************************************************************/

VectorDec VectorDec::operator+ (VectorDec& v2)
{
    return VectorDec {x_ + v2.getX(), y_ + v2.getY()};
}

VectorDec VectorDec::operator* (int mul)
{
    return VectorDec {x_ * mul, y_ * mul};
}

VectorDec VectorDec::operator- ()
{
    return VectorDec {-x_, -y_};
}

VectorDec VectorDec::operator~ ()
{
    return VectorDec {y_, -x_};
}

VectorDec VectorDec::operator! ()
{
    return VectorDec {x_ / abs(x_), y_ / abs(y_)};
}


/**************************************************************************/

int VectorDec::getX ()
{
    return x_;
}

int VectorDec::getY ()
{
    return y_;
}

/**************************************************************************/

void VectorDec::setX (int x)
{
    x_ = x;
}

void VectorDec::setY (int y)
{
    y_ = y;
}

/**************************************************************************/
