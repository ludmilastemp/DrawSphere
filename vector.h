#ifndef STL_vector
#define STL_vector

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "vectorDec.h"
#include "vectorPol.h"

/// const_cast

////////////////////////////
enum VectorStatus
{
    DEC,
    POL,
    ALL,
};

class Vector
{
private:

    VectorDec dec_ {};
    VectorPol pol_ {};

    VectorStatus stat_ {ALL};

    void updateDec ();
    void updatePol ();

public:

    Vector (x_t x, int y);
    Vector (int len, double phi);
    Vector (const VectorDec& vDec);
    Vector (const VectorPol& vPol);

    Vector operator+ (const Vector& v2) const;
    Vector operator- (const Vector& v2) const;
    Vector operator- () const;
    Vector operator* (const int mul) const;
    Vector operator/ (const int mul) const;

    void normalize ();
    void perpendicular ();

    x_t getX (); 
    y_t getY ();
    len_t getLen ();
    phi_t getPhi ();
    
    void setX (x_t x);
    void setY (y_t y);
    void setLen (len_t len);
    void setPhi (phi_t phi);
    void setStat (VectorStatus stat);

    friend Vector NormalizeVector     (const Vector& v); /////////////////////////
    friend Vector PerpendicularVector (const Vector& v); /////////////////////////
};


#endif /* STL_vector */