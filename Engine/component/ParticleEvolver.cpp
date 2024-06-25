#include "ParticleEvolver.h"

NS_JYE_BEGIN

//
// ParticleEvolver
//
IMPLEMENT_RTTI_NoCreateFun(ParticleEvolver, Object);

IMPLEMENT_INITIAL_NO_CLASS_FACTORY_BEGIN(ParticleEvolver)
IMPLEMENT_INITIAL_NO_CLASS_FACTORY_END


//
// ParticleSize
//
IMPLEMENT_RTTI(ParticleSize, ParticleEvolver);

IMPLEMENT_INITIAL_BEGIN(ParticleSize)
IMPLEMENT_INITIAL_END

//
// ParticleColor
//
IMPLEMENT_RTTI(ParticleColor, ParticleEvolver);

IMPLEMENT_INITIAL_BEGIN(ParticleColor)
IMPLEMENT_INITIAL_END

//
// ParticleRotation
//
IMPLEMENT_RTTI(ParticleRotation, ParticleEvolver);

IMPLEMENT_INITIAL_BEGIN(ParticleRotation)
IMPLEMENT_INITIAL_END


NS_JYE_END