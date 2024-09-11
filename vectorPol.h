#ifndef STL_vectorPol
#define STL_vectorPol

#include <stdio.h>
#include <math.h>
#include <assert.h>

const double PI = 3.14;

typedef int len_t;
typedef double phi_t;

class VectorPol
{
public:

    len_t len_ {}; 
    phi_t phi_ {}; 

    VectorPol (len_t len = 0, phi_t phi = 0);
    VectorPol (const VectorPol& vPol);

    VectorPol operator+ (const VectorPol& v2) const;
    VectorPol operator- (const VectorPol& v2) const;
    VectorPol operator- () const;
    VectorPol operator* (const int mul) const;
    VectorPol operator/ (const int mul) const;

    void normalize ();
    void perpendicular ();
};

VectorPol NormalizeVector     (const VectorPol& v);
VectorPol PerpendicularVector (const VectorPol& v);


#endif /* STL_vectorPol */