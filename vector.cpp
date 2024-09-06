#include "vector.h"

// DANGEROUS!!! все операторы определены только для декартовой системы 

/**************************************************************************/

Vector::Vector (int x, int y) 
    : dec_ {x, y}, pol_ {}, stat_ {DEC}
{}

Vector::Vector (const VectorDec& vDec) 
    : dec_ {vDec}, pol_ {}, stat_ {DEC}
{}

Vector::Vector (int len, double phi) 
    : dec_ {}, pol_ {len, phi}, stat_ {POL}
{
    dec_.setX (len * cos(1.0 * phi * acos(-1) / 180.0));
    dec_.setY (len * sin(1.0 * phi * acos(-1) / 180.0));
    stat_ = DEC;
}

Vector::Vector (const VectorPol& vPol) 
    : dec_ {}, pol_ {vPol}, stat_ {POL}
{}

/**************************************************************************/

Vector Vector::operator+ (Vector& v2)
{
    if (stat_ == DEC) return Vector {dec_ + v2.dec_};
    assert (0);
}

Vector Vector::operator* (int mul)
{
    if (stat_ == DEC) return dec_ * mul;
    assert (0);
}

Vector Vector::operator- ()
{
    if (stat_ == DEC) return -dec_;
    assert (0);
}

Vector Vector::operator~ ()
{
    if (stat_ == DEC) return ~dec_;
    assert (0);
}

Vector Vector::operator! ()
{
    if (stat_ == DEC) return !dec_;
    assert (0);
}


/**************************************************************************/

// void Vector::updateDec ()
// {
//     x_ = len_ * cos(1.0 * phi_ * acos(-1) / 180.0);
//     y_ = len_ * sin(1.0 * phi_ * acos(-1) / 180.0);
//     stat_ = ALL;
// }

// void Vector::updatePol ()
// {
//     len_ = sqrt (x_ * x_ + y_ * y_);
    
//     if (x_ == 0)
//         phi_ = 90 * y_ / abs (y_);
//     else 
//         phi_ = y_ / x_;

//     stat_ = ALL;
// }

/**************************************************************************/

int Vector::getX ()
{
    if (stat_== DEC) return dec_.getX();
    assert(0);
}

int Vector::getY ()
{
    if (stat_== DEC) return dec_.getY();
    assert(0);
}

int Vector::getLen ()
{
    if (stat_== POL) return pol_.getLen();
    assert(0);
}

int Vector::getPhi ()
{
    if (stat_== POL) return pol_.getPhi();
    assert(0);
}

/**************************************************************************/

void Vector::setX (int x)
{
    if (stat_== DEC) dec_.setX(x);
    else assert(0);
}

void Vector::setY (int y)
{
    if (stat_== DEC) dec_.setY(y);
    else assert(0);
}

void Vector::setLen (int len)
{
    if (stat_ == POL) pol_.setLen(len);
    else assert(0);
    stat_ = POL;
}

void Vector::setPhi (int phi)
{
    if (stat_ == POL) pol_.setPhi(phi);
    if (stat_ == DEC) 
    {
        dec_.setX (pol_.getLen() * cos(1.0 * phi * acos(-1) / 180.0));
        dec_.setY (pol_.getLen() * sin(1.0 * phi * acos(-1) / 180.0));
    }
    else assert(0);
    
}

/**************************************************************************/
