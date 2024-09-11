#ifndef STL_vectorPol
#define STL_vectorPol

using len_t = int;
using phi_t = double;

class VectorPol
{
public:

    len_t len {}; 
    phi_t phi {}; 

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