#ifndef STL_vectorDec
#define STL_vectorDec

#include <stdio.h>
#include <math.h>
#include <assert.h>

/// const_cast

class VectorDec
{
private:

    int x_ {}; 
    int y_ {};

public:

    VectorDec (int x = 0, int y = 0);
    VectorDec (const VectorDec& vDec);

    VectorDec operator+ (VectorDec& v2);
    VectorDec operator* (int mul);
    VectorDec operator- ();
    VectorDec operator~ (); /* перпендикулярный вектор */
    VectorDec operator! (); /* нормализованный  вектор */ // do not working

    int getX (); 
    int getY ();
    
    void setX (int x);
    void setY (int y);
};

#endif /* STL_vectorDec */