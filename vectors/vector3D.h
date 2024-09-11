#ifndef STL_Vector3D
#define STL_Vector3D

using coord_t = int;

class Vector3D
{
public:

    coord_t x {}; 
    coord_t y {};
    coord_t z {};

    Vector3D (coord_t x = 0, coord_t y = 0, coord_t z = 0);
    // Vector3D (const Vector3D& v3D);

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