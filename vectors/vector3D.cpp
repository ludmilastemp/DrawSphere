#include "vector3D.h"

#include <stdio.h>
#include <math.h>
#include <assert.h>

/**************************************************************************/

Vector3D::Vector3D (coord_3d_t init_x, coord_3d_t init_y, coord_3d_t init_z) 
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

Vector3D Vector3D::operator* (const double mul) const
{
    return Vector3D {x * mul, y * mul, z * mul};
}

Vector3D Vector3D::operator/ (const double mul) const
{
    // return this * (1 / mul);
    return Vector3D {x / mul, y / mul, z / mul};
}

Vector3D Vector3D::operator- () const
{
    return Vector3D {-x, -y, -z}; 
}

/**************************************************************************/

Vector3D ReflectVector (const Vector3D& vector, const Vector3D& line)
{
    Vector3D lineNorm = line / GetLen(line);
    Vector3D projection = lineNorm * (CalculateDotProduct (vector, lineNorm));
    return projection * 2 - vector;
}

double GetLen (const Vector3D& v)
{
    return sqrt(CalculateDotProduct(v, v));
}

double CalculateDotProduct (const Vector3D& v1, const Vector3D& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; 
}

double CalculateCosAngle (const Vector3D& v1, const Vector3D& v2)
{
    return CalculateDotProduct (v1, v2) / (GetLen(v1) * GetLen(v2));
}

/**************************************************************************/
