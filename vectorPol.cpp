#include "vectorPol.h"

/**************************************************************************/

VectorPol::VectorPol (len_t len, phi_t phi)
    : len_(len), phi_(phi)
{}

VectorPol::VectorPol (const VectorPol& vPol) 
    : len_(vPol.len_), phi_(vPol.phi_)
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
    return VectorPol {len_ * mul, phi_};
}

VectorPol VectorPol::operator/ (const int mul) const
{
    return VectorPol {len_ / mul, phi_};
}

VectorPol VectorPol::operator- () const
{
    return VectorPol {len_, phi_ + PI};
}

/**************************************************************************/

void VectorPol::normalize ()
{
    len_ = 1;
}

void VectorPol::perpendicular ()
{
    phi_ = phi_ + PI / 2;
}

/**************************************************************************/

VectorPol NormalizeVector (const VectorPol& v) 
{
    return VectorPol {1, v.phi_};
}

VectorPol PerpendicularVector (const VectorPol& v) 
{
    return VectorPol {v.len_, v.phi_ + PI / 2};
}

/**************************************************************************/
