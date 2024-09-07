#ifndef STL_vectorPol
#define STL_vectorPol

#include <stdio.h>
#include <math.h>
#include <assert.h>

/// const_cast

const double PI = 3.14;

typedef int len_t;
typedef double phi_t;

class VectorPol
{
private:

    len_t len_ {}; 
    phi_t phi_ {}; 

public:

    VectorPol (len_t len = 0, phi_t phi = 0);
    VectorPol (const VectorPol& vPol);

    VectorPol operator+ (const VectorPol& v2) const;
    VectorPol operator* (const int mul) const;
    VectorPol operator- () const;
    VectorPol operator~ () const; /* перпендикулярный вектор */
    VectorPol operator! () const; /* нормализованный  вектор */ // do not working

    len_t getLen () const;
    phi_t getPhi () const;
    
    void setLen (len_t len);
    void setPhi (phi_t phi);
};


#endif /* STL_vectorPol */