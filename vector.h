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

class Vector
{
    int x;

    public:
        int y;
        int l;
        int a;
        CORRECT_STATUS stat;

        int GetX ();
        int GetY ();
        int GetL ();
        int GetA ();
        
        void SetX (int x);
        void SetY (int y);
        void SetL (int x);
        void SetA (int a);
        void SetStat (CORRECT_STATUS stat);

        void ToDec ();
        void ToPol ();
};

Vector CtorDecVector (int x, int y);
Vector CtorPolVector (int x, int y);

Vector SumVector  (Vector v1, Vector v2);
Vector PerVector  (Vector v1);
Vector SwapVector (Vector v1);


// const Vector c00 = CtorDecVector (400, 300);

#endif /* STL_vector */