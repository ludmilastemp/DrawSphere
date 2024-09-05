#include "vector.h"

/**************************************************************************/

Vector CtorDecVector (int x, int y)
{
    Vector v;
    v.SetStat(dec);
    v.SetX(x);
    v.SetY(y);
    return v;
}

Vector CtorPolVector (int l, int a)
{
    Vector v;
    v.SetStat(pol);
    v.SetL(l);
    v.SetA(a);
    return v;
}

/**************************************************************************/

void Vector::ToDec ()
{
    x = l * cos(1.0 * a * acos(-1) / 180.0);
    y = l * sin(1.0 * a * acos(-1) / 180.0);
    stat = all;
}

void Vector::ToPol ()
{
    l = sqrt (x * x + y * y);
    a = y / x;
    stat = all;
}

/**************************************************************************/

int Vector::GetX ()
{
    if (stat == pol) ToDec();
    return x;
}

int Vector::GetY ()
{
    if (stat == pol) ToDec();
    return y;
}

int Vector::GetL ()
{
    if (stat == dec) ToPol();
    return l;
}

int Vector::GetA ()
{
    if (stat == dec) ToPol();
    return a;
}

/**************************************************************************/

void Vector::SetX (int x_new)
{
    if (stat == pol) ToDec();
    x = x_new;
    stat = dec;
}

void Vector::SetY (int y_new)
{
    if (stat == pol) ToDec();
    y = y_new;
    stat = dec;
}

void Vector::SetL (int l_new)
{
    if (stat == dec) ToPol();
    l = l_new;
    stat = pol;
}

void Vector::SetA (int a_new)
{
    if (stat == dec) ToPol();
    a = a_new;
    stat = pol;
}

void Vector::SetStat (CORRECT_STATUS stat_new)
{
    stat = stat_new;
}

/**************************************************************************/

Vector SumVector (Vector v1, Vector v2)
{
    Vector v = CtorDecVector (v1.GetX() + v2.GetX(), v1.GetY() + v2.GetY());
    return v;
}

Vector PerVector (Vector v1)
{
    Vector v = CtorDecVector (v1.GetY(), -v1.GetX());
    return v;
}

Vector SwapVector (Vector v1)
{
    Vector v = CtorDecVector (-v1.GetX(), -v1.GetY());
    return v;
}

/**************************************************************************/
