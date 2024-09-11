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
    dec_.x_ = pol_.len_ * cos(pol_.phi_);
    dec_.y_ = pol_.len_ * sin(pol_.phi_);

    stat_ = ALL;
}

void Vector::updatePol ()
{
    pol_.len_ = sqrt (dec_.x_ * dec_.x_ + dec_.y_ * dec_.y_);

    double phi = 0;
    if (dec_.x_ == 0)
        phi = PI / 2 * dec_.y_ / abs(dec_.y_);
    else if (dec_.x_ > 0)
        phi = dec_.y_ / dec_.x_;
    else
        phi = PI + dec_.y_ / dec_.x_;

    pol_.phi_ = phi;
    
    stat_ = ALL;
}

/**************************************************************************/

int Vector::getX ()
{
    if (stat_== POL) updateDec ();
    return dec_.x_;
}

int Vector::getY ()
{
    if (stat_== POL) updateDec ();
    return dec_.y_;
}

int Vector::getLen ()
{
    if (stat_== DEC) updatePol ();
    return pol_.len_;
}

double Vector::getPhi ()
{
    if (stat_== DEC) updatePol ();
    return pol_.phi_;
}

/**************************************************************************/

void Vector::setX (int x)
{
    if (stat_== POL) updateDec ();
    dec_.x_ = x;
    stat_ = DEC;
}

void Vector::setY (int y)
{
    if (stat_== POL) updateDec ();
    dec_.y_ = y;
    stat_ = DEC;
}

void Vector::setLen (int len)
{
    if (stat_ == DEC) updatePol ();
    pol_.len_ = len;
    stat_ = POL;
}

void Vector::setPhi (double phi)
{
    if (stat_ == DEC) updatePol ();
    pol_.phi_ = phi;
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
