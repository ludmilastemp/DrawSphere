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
    assert (0);
    return v2;
}

VectorPol VectorPol::operator* (const int mul) const
{
    return VectorPol {len_ * mul, phi_};
}

VectorPol VectorPol::operator- () const
{
    return VectorPol {len_, phi_ + PI};
}

VectorPol VectorPol::operator~ () const
{
    return VectorPol {len_, phi_ + PI / 2};
}

VectorPol VectorPol::operator! () const
{
    return VectorPol {1, phi_};
}

/**************************************************************************/
