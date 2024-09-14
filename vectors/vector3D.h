#ifndef STL_Vector3D
#define STL_Vector3D

using coord_3d_t = double;

class Vector3D
{
public:

    coord_3d_t x {}; 
    coord_3d_t y {};
    coord_3d_t z {};

    Vector3D (coord_3d_t x = 0, coord_3d_t y = 0, coord_3d_t z = 0);
    // Vector3D (const Vector3D& v3D);

    Vector3D operator+ (const Vector3D& v2) const;
    Vector3D operator- (const Vector3D& v2) const;
    Vector3D operator* (const double mul) const;
    Vector3D operator/ (const double mul) const;
    Vector3D operator- () const;
};

double GetLen (const Vector3D& v);

Vector3D ReflectVector       (const Vector3D& vector, const Vector3D& line);
double   CalculateDotProduct (const Vector3D& v1,     const Vector3D& v2);
double   CalculateCosAngle   (const Vector3D& v1,     const Vector3D& v2);

#endif /* STL_Vector3D */