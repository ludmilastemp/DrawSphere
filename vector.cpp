#include "vector.h"

Vector ToDec (Vector v);
Vector ToPol (Vector v);

Vector CtorDecVector (int x, int y)
{
    Vector v = {x, y, 0, 0, dec};
    return v;
}

Vector CtorPolVector (int l, int a)
{
    Vector v = {0, 0, l, a, pol};
    return v;
}

Vector SumVector (Vector v1, Vector v2)
{
    Vector v = {GetX(v1) + GetX(v2), GetY(v1) + GetY(v2)};
    return v;
}

Vector PerVector (Vector v1)
{
    Vector v = {GetY(v1), -GetX(v1)};
    return v;
}

Vector SwapVector (Vector v1)
{
    Vector v = {-GetX(v1), -GetY(v1)};
    return v;
}

Vector ToDec (Vector v)
{
    v.x = GetL (v) * cos(1.0 * GetA (v) * acos(-1) / 180.0);
    v.y = GetL (v) * sin(1.0 * GetA (v) * acos(-1) / 180.0);
    SetStat (v, all);
    return v;
}

Vector ToPol (Vector v)
{
    v.l = sqrt (GetX (v) * GetX (v) + GetY (v) * GetY (v));
    v.a = GetY (v) / GetX (v);
    SetStat (v, all);
    return v;
}

int GetX (Vector v)
{
    if (GetStat (v) == pol) v = ToDec (v);
    return v.x;
}

int GetY (Vector v)
{
    if (GetStat (v) == pol) v = ToDec (v);
    return v.y;
}

int GetL (Vector v)
{
    if (GetStat (v) == dec) v = ToPol (v);
    return v.l;
}

int GetA (Vector v)
{
    if (GetStat (v) == dec) v = ToPol (v);
    return v.a;
}

CORRECT_STATUS GetStat (Vector v)
{
    return v.stat;
}

void SetX (Vector& v, int x)
{
    if (GetStat (v) == pol) v = ToDec (v);
    v.x = x;
    SetStat (v, dec);
}

void SetY (Vector& v, int y)
{
    if (GetStat (v) == pol) v = ToDec (v);
    v.y = y;
    SetStat (v, dec);
}

void SetL (Vector& v, int l)
{
    if (GetStat (v) == dec) v = ToPol (v);
    v.l = l;
    SetStat (v, pol);
}

void SetA (Vector& v, int a)
{
    if (GetStat (v) == dec) v = ToPol (v);
    v.a = a;
    SetStat (v, pol);
}

void SetStat (Vector& v, CORRECT_STATUS s)
{
    v.stat = s;
}