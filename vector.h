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

    // void updateDec ();
    // void updatePol ();

public:

    Vector (int x, int y);
    Vector (int len, double phi);
    Vector (const VectorDec& vDec);
    Vector (const VectorPol& vPol);

    // Vector (int len, double a);

    Vector operator+ (Vector& v2);
    Vector operator* (int mul);
    Vector operator- ();
    Vector operator~ (); /* перпендикулярный вектор */
    Vector operator! (); /* нормализованный  вектор */ 

    int getX (); 
    int getY ();
    int getLen ();
    int getPhi ();
    
    void setX (int x);
    void setY (int y);
    void setLen (int x);
    void setPhi (int a);
    void setStat (VectorStatus stat);
};

#endif /* STL_vector */