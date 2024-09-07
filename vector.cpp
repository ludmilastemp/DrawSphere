#include "vector.h"

/**************************************************************************/

Vector::Vector (int x, int y) 
    : dec_ {x, y}, pol_ {}, stat_ {DEC}
{}

Vector::Vector (const VectorDec& vDec) 
    : dec_ {vDec}, pol_ {}, stat_ {DEC}
{}

Vector::Vector (int len, double phi) 
    : dec_ {}, pol_ {len, phi}, stat_ {POL}
{}

Vector::Vector (const VectorPol& vPol) 
    : dec_ {}, pol_ {vPol}, stat_ {POL}
{}

/**************************************************************************/

Vector Vector::operator+ (const Vector& v2) const
{
    if (stat_ == DEC) 
        return Vector {dec_ + v2.dec_};
    else
        return Vector {pol_ + v2.pol_};
}

Vector Vector::operator* (const int mul) const
{
    if (stat_ == DEC) 
        return dec_ * mul;
    else
        return pol_ * mul;
}

Vector Vector::operator- () const
{
    if (stat_ == DEC) 
        return -dec_;
    else
        return -pol_;
}

Vector Vector::operator~ () const
{
    if (stat_ == DEC) 
        return ~dec_;
    else   
        return ~pol_;
}

Vector Vector::operator! () const
{
    if (stat_ == DEC) 
        return !dec_;
    else
        return !pol_;
}


/**************************************************************************/

void Vector::updateDec ()
{
    dec_.setX (pol_.getLen () * cos(pol_.getPhi ()));
    dec_.setY (pol_.getLen () * sin(pol_.getPhi ()));

    stat_ = ALL;
}

void Vector::updatePol ()
{
    pol_.setLen (sqrt (dec_.getX () * dec_.getX () + dec_.getY () * dec_.getY ()));

    double phi = 0;
    if (dec_.getX () == 0)
        phi = PI / 2 * dec_.getY () / abs(dec_.getY ());
    else if (dec_.getX () > 0)
        phi = dec_.getY () / dec_.getX ();
    else
        phi = PI + dec_.getY () / dec_.getX ();

    pol_.setPhi (phi);
    
    stat_ = ALL;
}

/**************************************************************************/

int Vector::getX ()
{
    if (stat_== POL) updateDec ();
    return dec_.getX ();
}

int Vector::getY ()
{
    if (stat_== POL) updateDec ();
    return dec_.getY ();
}

int Vector::getLen ()
{
    if (stat_== DEC) updatePol ();
    return pol_.getLen ();
}

double Vector::getPhi ()
{
    if (stat_== DEC) updatePol ();
    return pol_.getPhi ();
}

/**************************************************************************/

void Vector::setX (int x)
{
    if (stat_== POL) updateDec ();
    dec_.setX(x);
    stat_ = DEC;
}

void Vector::setY (int y)
{
    if (stat_== POL) updateDec ();
    dec_.setY(y);
    stat_ = DEC;
}

void Vector::setLen (int len)
{
    if (stat_ == DEC) updatePol ();
    pol_.setLen(len);
    stat_ = POL;
}

void Vector::setPhi (double phi)
{
    if (stat_ == DEC) updatePol ();
    pol_.setPhi(phi);
    stat_ = POL;
}

/**************************************************************************/
