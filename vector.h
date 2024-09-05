#ifndef STL_vector
#define STL_vector

#include <math.h>
#include <assert.h>

enum CORRECT_STATUS
{
    dec,
    pol,
    all,
};

struct Vector
{
    int x;
    int y;
    int l;
    int a;
    CORRECT_STATUS stat;
};

const Vector c00 = {400, 300};

Vector CtorDecVector (int x, int y);
Vector CtorPolVector (int l, int a);
Vector SumVector  (Vector v1, Vector v2);
Vector PerVector  (Vector v1);
Vector SwapVector (Vector v1);
int GetX (Vector v);
int GetY (Vector v);
int GetL (Vector v);
int GetA (Vector v);
CORRECT_STATUS GetStat (Vector v);
void SetX (Vector& v, int x);
void SetY (Vector& v, int y);
void SetL (Vector& v, int x);
void SetA (Vector& v, int a);
void SetStat (Vector& v, CORRECT_STATUS s);

#endif /* STL_vector */