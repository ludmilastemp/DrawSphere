#ifndef STL_vector
#define STL_vector

#include <stdio.h>
#include <math.h>
#include <assert.h>

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

    int x_ {}; 
    int y_ {};
    int len_ {}; 
    int phi_ {}; 
    VectorStatus stat_ {ALL};

    void updateDec ();
    void updatePol ();

public:

    Vector (int x, int y);
    Vector (int len, double a);

    Vector operator+ (Vector& v2);
    Vector operator* (int mul);
    Vector operator- ();
    Vector operator~ (); /* перпендикулярный вектор */
    Vector operator! (); /* нормализованный  вектор */ // do not working

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

const Vector c00 {400, 300};

#endif /* STL_vector */