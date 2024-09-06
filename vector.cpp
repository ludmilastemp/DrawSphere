#include "vector.h"

// DANGEROUS!!! все операторы определены только для декартовой системы (еще и без проверок)!!!

/**************************************************************************/

Vector::Vector (int x, int y) 
    : x_(x), y_(y), stat_(DEC)
{}

Vector::Vector (int len, double phi)
    : len_(len), phi_((int)phi), stat_(POL)
{}

/**************************************************************************/

Vector Vector::operator+ (Vector& v2)
{
    return Vector {x_ + v2.getX(), y_ + v2.getY()};
}

Vector Vector::operator* (int mul)
{
    return Vector {x_ * mul, y_ * mul};
}

Vector Vector::operator- ()
{
    return Vector {-x_, -y_};
}

Vector Vector::operator~ ()
{
    return Vector {y_, -x_};
}

Vector Vector::operator! ()
{
    return Vector {x_ / abs(x_), y_ / abs(y_)};
}


/**************************************************************************/

void Vector::updateDec ()
{
    x_ = len_ * cos(1.0 * phi_ * acos(-1) / 180.0);
    y_ = len_ * sin(1.0 * phi_ * acos(-1) / 180.0);
    stat_ = ALL;
}

void Vector::updatePol ()
{
    len_ = sqrt (x_ * x_ + y_ * y_);
    
    if (x_ == 0)
        phi_ = 90 * y_ / abs (y_);
    else 
        phi_ = y_ / x_;

    stat_ = ALL;
}

/**************************************************************************/

int Vector::getX ()
{
    if (stat_ == POL) updateDec(); 
    return x_;
}

int Vector::getY ()
{
    if (stat_ == POL) updateDec();
    return y_;
}

int Vector::getLen ()
{
    if (stat_ == DEC) updatePol();
    return len_;
}

int Vector::getPhi ()
{
    if (stat_ == DEC) updatePol();
    return phi_;
}

/**************************************************************************/

void Vector::setX (int x)
{
    if (stat_ == POL) updateDec();
    x_ = x;
    stat_ = DEC;
}

void Vector::setY (int y)
{
    if (stat_ == POL) updateDec();
    y_ = y;
    stat_ = DEC;
}

void Vector::setLen (int len)
{
    if (stat_ == DEC) updatePol();
    len_ = len;
    stat_ = POL;
}

void Vector::setPhi (int phi)
{
    if (stat_ == DEC) updatePol();
    phi_ = phi;
    stat_ = POL;
}

void Vector::setStat (VectorStatus stat)
{
    stat_ = stat;
}

/**************************************************************************/

/**************************************************************************/
