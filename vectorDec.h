#ifndef STL_vectorDec
#define STL_vectorDec

#include <stdio.h>
#include <math.h>
#include <assert.h>

/// const_cast

typedef int x_t;
typedef int y_t;

class VectorDec
{
public:

    x_t x_ {}; 
    y_t y_ {};

    VectorDec (x_t x = 0, y_t y = 0);
    VectorDec (const VectorDec& vDec);

    VectorDec operator+ (const VectorDec& v2) const;
    VectorDec operator* (const int mul) const;
    VectorDec operator- () const;
    VectorDec operator~ () const; /* перпендикулярный вектор */
    VectorDec operator! () const; /* нормализованный  вектор */ // do not working
};

#endif /* STL_vectorDec */