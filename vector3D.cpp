#include "vector3D.h"

/**************************************************************************/

Vector3D::Vector3D (x_t init_x, y_t init_y, z_t init_z) 
    : x(init_x), y(init_y), z(init_z)
{}

// Vector3D::Vector3D (const Vector3D& v3D) 
//     : x(v3D.x), y(v3D.y), z(v3D.z)
// {}

/**************************************************************************/

Vector3D Vector3D::operator+ (const Vector3D& v2) const
{
    return Vector3D {x + v2.x, y + v2.y, z + v2.z};
}

Vector3D Vector3D::operator- (const Vector3D& v2) const
{
    return Vector3D {x - v2.x, y - v2.y, z - v2.z};
}

Vector3D Vector3D::operator* (const int mul) const
{
    return Vector3D {x * mul, y * mul, z * mul};
}

Vector3D Vector3D::operator/ (const int mul) const
{
    return Vector3D {x / mul, y / mul, z / mul};
}

Vector3D Vector3D::operator- () const
{
    return Vector3D {-x, -y, -z};
}

/**************************************************************************/

double GetLen (const Vector3D& v)
{
    return sqrt(GetLen_2(v));
}

int GetLen_2 (const Vector3D& v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

int CalculateDotProduct (const Vector3D& v1, const Vector3D& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; 
}

double CalculateCosAngle (const Vector3D& v1, const Vector3D& v2)
{
    return CalculateDotProduct (v1, v2) / (GetLen(v1) * GetLen(v2));
}

/**************************************************************************/
