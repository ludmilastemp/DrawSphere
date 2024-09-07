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
private:

    x_t x_ {}; 
    y_t y_ {};

public:

    VectorDec (x_t x = 0, y_t y = 0);
    VectorDec (const VectorDec& vDec);

    VectorDec operator+ (const VectorDec& v2) const;
    VectorDec operator* (const int mul) const;
    VectorDec operator- () const;
    VectorDec operator~ () const; /* перпендикулярный вектор */
    VectorDec operator! () const; /* нормализованный  вектор */ // do not working

    x_t getX () const; 
    y_t getY () const;
    
    void setX (x_t x);
    void setY (y_t y);
};

#endif /* STL_vectorDec */