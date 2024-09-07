#include "vectorDec.h"

/**************************************************************************/

VectorDec::VectorDec (x_t x, y_t y) 
    : x_(x), y_(y)
{}

VectorDec::VectorDec (const VectorDec& vDec) 
    : x_(vDec.x_), y_(vDec.y_)
{}

/**************************************************************************/

VectorDec VectorDec::operator+ (const VectorDec& v2) const
{
    return VectorDec {x_ + v2.x_, y_ + v2.y_};
}

VectorDec VectorDec::operator* (const int mul) const
{
    return VectorDec {x_ * mul, y_ * mul};
}

VectorDec VectorDec::operator- () const
{
    return VectorDec {-x_, -y_};
}

VectorDec VectorDec::operator~ () const
{
    return VectorDec {y_, -x_};
}

VectorDec VectorDec::operator! () const
{
    return VectorDec {x_ / abs(x_), y_ / abs(y_)};
}

/**************************************************************************/
