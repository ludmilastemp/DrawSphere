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
    Vector v = {v1.x + v2.x, v1.y + v2.y};
    return v;
}

Vector PerVector (Vector v1)
{
    Vector v = {v1.y, -v1.x};
    return v;
}

Vector SwapVector (Vector v1)
{
    Vector v = {-v1.x, -v1.y};
    return v;
}

Vector ToDec (Vector v)
{
    v.x = v.l * cos(1.0 * v.a * acos(-1) / 180.0);
    v.y = v.l * sin(1.0 * v.a * acos(-1) / 180.0);
    v.stat = all;
    return v;
}

Vector ToPol (Vector v)
{
    v.l = sqrt (v.x * v.x + v.y * v.y);
    v.a = v.y / v.x;
    v.stat = all;
    return v;
}

int GetX (Vector v)
{
    if (v.stat == pol) v = ToDec (v);
    return v.x;
}

int GetY (Vector v)
{
    if (v.stat == pol) v = ToDec (v);
    return v.y;
}

int GetL (Vector v)
{
    if (v.stat == dec) v = ToPol (v);
    return v.l;
}

int GetA (Vector v)
{
    if (v.stat == dec) v = ToPol (v);
    return v.a;
}

Vector SetX (Vector v, int x)
{
    if (v.stat == pol) v = ToDec (v);
    v.x = x;
    v.stat = dec;
    return v;
}

Vector SetY (Vector v, int y)
{
    if (v.stat == pol) v = ToDec (v);
    v.y = y;
    v.stat = dec;
    return v;
}

Vector SetL (Vector v, int l)
{
    if (v.stat == dec) v = ToPol (v);
    v.l = l;
    v.stat = pol;
    return v;
}

Vector SetA (Vector v, int a)
{
    if (v.stat == dec) v = ToPol (v);
    v.a = a;
    v.stat = pol;
    return v;
}