#include "vector.h"

#include <stdio.h>
#include <math.h>
#include <assert.h>

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

Vector Vector::operator- (const Vector& v2) const
{
    if (stat_ == DEC) 
        return Vector {dec_ - v2.dec_};
    else
        return Vector {pol_ - v2.pol_};
}

Vector Vector::operator* (const int mul) const
{
    if (stat_ == DEC) 
        return dec_ * mul;
    else
        return pol_ * mul;
}

Vector Vector::operator/ (const int mul) const
{
    if (stat_ == DEC) 
        return dec_ / mul;
    else
        return pol_ / mul;
}

Vector Vector::operator- () const
{
    if (stat_ == DEC) 
        return -dec_;
    else
        return -pol_;
}

/**************************************************************************/

void Vector::normalize ()
{
    if (stat_ == DEC) 
        return dec_.normalize();
    else
        return pol_.normalize();
}

void Vector::perpendicular ()
{
    if (stat_ == DEC) 
        return dec_.perpendicular();
    else   
        return pol_.perpendicular();
}

/**************************************************************************/

void Vector::updateDec ()
{
    dec_.x = pol_.len * cos(pol_.phi);
    dec_.y = pol_.len * sin(pol_.phi);

    stat_ = ALL;
}

void Vector::updatePol ()
{
    pol_.len = sqrt (dec_.x * dec_.x + dec_.y * dec_.y);

    double phi = 0;
    if (dec_.x == 0)
        phi = M_PI / 2 * dec_.y / abs(dec_.y);
    else if (dec_.x > 0)
        phi = dec_.y / dec_.x;
    else
        phi = M_PI + dec_.y / dec_.x;

    pol_.phi = phi;
    
    stat_ = ALL;
}

/**************************************************************************/

int Vector::getX ()
{
    if (stat_== POL) updateDec ();
    return dec_.x;
}

int Vector::getY ()
{
    if (stat_== POL) updateDec ();
    return dec_.y;
}

int Vector::getLen ()
{
    if (stat_== DEC) updatePol ();
    return pol_.len;
}

double Vector::getPhi ()
{
    if (stat_== DEC) updatePol ();
    return pol_.phi;
}

/**************************************************************************/

void Vector::setX (int x)
{
    if (stat_== POL) updateDec ();
    dec_.x = x;
    stat_ = DEC;
}

void Vector::setY (int y)
{
    if (stat_== POL) updateDec ();
    dec_.y = y;
    stat_ = DEC;
}

void Vector::setLen (int len)
{
    if (stat_ == DEC) updatePol ();
    pol_.len = len;
    stat_ = POL;
}

void Vector::setPhi (double phi)
{
    if (stat_ == DEC) updatePol ();
    pol_.phi = phi;
    stat_ = POL;
}

/**************************************************************************/

Vector NormalizeVector (const Vector& v) 
{
    if (v.stat_ == DEC) 
        return NormalizeVector (v.dec_);
    else
        return NormalizeVector (v.pol_);
}

Vector PerpendicularVector (const Vector& v) 
{
    if (v.stat_ == DEC) 
        return PerpendicularVector (v.dec_);
    else   
        return PerpendicularVector (v.pol_);
}

/**************************************************************************/
