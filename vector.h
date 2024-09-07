#ifndef STL_vector
#define STL_vector

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "vectorDec.h"
#include "vectorPol.h"

/// const_cast

class Vector
{
private:

    enum VectorStatus
    {
        DEC,
        POL,
        ALL,
    };

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

    // Vector (int len, double a);

    Vector operator+ (const Vector& v2) const;
    Vector operator* (const int mul) const;
    Vector operator- () const;
    Vector operator~ () const; /* перпендикулярный вектор */
    Vector operator! () const; /* нормализованный  вектор */ 

    x_t getX (); 
    int getY ();
    int getLen ();
    double getPhi ();
    
    void setX (x_t x);
    void setY (int y);
    void setLen (int len);
    void setPhi (double phi);
    void setStat (VectorStatus stat);
};

#endif /* STL_vector */