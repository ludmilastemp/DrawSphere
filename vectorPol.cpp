#include "vectorPol.h"

#include <stdio.h>
#include <math.h>
#include <assert.h>

/**************************************************************************/

VectorPol::VectorPol (len_t len_init, phi_t phi_init)
    : len(len_init), phi(phi_init)
{}

VectorPol::VectorPol (const VectorPol& vPol) 
    : len(vPol.len), phi(vPol.phi)
{}

/**************************************************************************/

VectorPol VectorPol::operator+ (const VectorPol& v2) const
{
    assert (0); return v2;
}

VectorPol VectorPol::operator- (const VectorPol& v2) const
{
    assert (0); return v2;
}

VectorPol VectorPol::operator* (const int mul) const
{
    return VectorPol {len * mul, phi};
}

VectorPol VectorPol::operator/ (const int mul) const
{
    return VectorPol {len / mul, phi};
}

VectorPol VectorPol::operator- () const
{
    return VectorPol {len, phi + M_PI};
}

/**************************************************************************/

void VectorPol::normalize ()
{
    len = 1;
}

void VectorPol::perpendicular ()
{
    phi = phi + M_PI / 2;
}

/**************************************************************************/

VectorPol NormalizeVector (const VectorPol& v) 
{
    return VectorPol {1, v.phi};
}

VectorPol PerpendicularVector (const VectorPol& v) 
{
    return VectorPol {v.len, v.phi + M_PI / 2};
}

/**************************************************************************/
