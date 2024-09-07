#ifndef STL_vectorPol
#define STL_vectorPol

#include <stdio.h>
#include <math.h>
#include <assert.h>

/// const_cast

const double PI = 3.14;

class VectorPol
{
private:

    int len_ {}; 
    double phi_ {}; 

public:

    VectorPol (int len = 0, double phi = 0);
    VectorPol (const VectorPol& vPol);

    VectorPol operator+ (const VectorPol& v2) const;
    VectorPol operator* (const int mul) const;
    VectorPol operator- () const;
    VectorPol operator~ () const; /* перпендикулярный вектор */
    VectorPol operator! () const; /* нормализованный  вектор */ // do not working

    int getLen () const;
    double getPhi () const;
    
    void setLen (int len);
    void setPhi (double phi);
};


#endif /* STL_vectorPol */