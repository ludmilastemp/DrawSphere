#include "vectorPol.h"

/**************************************************************************/

VectorPol::VectorPol (int len, double phi)
    : len_(len), phi_((int)phi)
{}

VectorPol::VectorPol (const VectorPol& vPol) 
    : len_(vPol.len_), phi_(vPol.phi_)
{}

/**************************************************************************/
/*
VectorPol VectorPol::operator+ (VectorPol& v2)
{
    return VectorPol {};
}

VectorPol VectorPol::operator* (int mul)
{
    return VectorPol {};
}

VectorPol VectorPol::operator- ()
{
    return VectorPol {};
}

VectorPol VectorPol::operator~ ()
{
    return VectorPol {};
}

VectorPol VectorPol::operator! ()
{
    return VectorPol {};
}
*/

/**************************************************************************/

int VectorPol::getLen ()
{
    return len_;
}

int VectorPol::getPhi ()
{
    return phi_;
}

/**************************************************************************/

void VectorPol::setLen (int len)
{
    len_ = len;
}

void VectorPol::setPhi (int phi)
{
    phi_ = phi;
}

/**************************************************************************/

/**************************************************************************/
