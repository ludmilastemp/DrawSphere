#ifndef STL_vectorPol
#define STL_vectorPol

#include <stdio.h>
#include <math.h>
#include <assert.h>

/// const_cast

class VectorPol
{
private:

    int len_ {}; 
    int phi_ {}; 

public:

    VectorPol (int len = 0, double a = 0);
    VectorPol (const VectorPol& vPol);

    VectorPol operator+ (VectorPol& v2);
    VectorPol operator* (int mul);
    VectorPol operator- ();
    VectorPol operator~ (); /* перпендикулярный вектор */
    VectorPol operator! (); /* нормализованный  вектор */ // do not working

    int getLen ();
    int getPhi ();
    
    void setLen (int x);
    void setPhi (int a);
};


#endif /* STL_vectorPol */