#ifndef STL_Vector3D
#define STL_Vector3D

#include <stdio.h>
#include <math.h>
#include <assert.h>

/// const_cast

// один typefef
typedef int x_t;
typedef int y_t;
typedef int z_t;

class Vector3D
{
public:

    x_t x {}; 
    y_t y {};
    z_t z {};

    Vector3D (x_t init_x = 0, y_t init_y = 0, z_t init_z = 0);
    Vector3D (const Vector3D& v3D);

    Vector3D operator+ (const Vector3D& v2) const;
    Vector3D operator- (const Vector3D& v2) const;
    Vector3D operator* (const int mul) const;
    Vector3D operator/ (const int mul) const;
    Vector3D operator- () const;
};

double GetLen   (const Vector3D& v);
int    GetLen_2 (const Vector3D& v);

int    CalculateDotProduct (const Vector3D& v1, const Vector3D& v2);
double CalculateCosAngle   (const Vector3D& v1, const Vector3D& v2);

#endif /* STL_Vector3D */