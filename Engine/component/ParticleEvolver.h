#pragma once

#include "Core/Object.h"
#include "../private/Define.h"
#include "ParticleProperty.h"

NS_JYE_BEGIN

REFLECTION_TYPE(ParticleEvolver)
CLASS_API(ENGINE_API, ParticleEvolver : public Object, Fields)
{
    REFLECTION_BODY(ParticleEvolver);
	DECLARE_RTTI
	DECLARE_INITIAL
public:
    ParticleEvolver(Object* pHost) : Object(pHost) {}
	ParticleEvolver(Object* pHost, ParticleProperty::EvolverType t) : Object(pHost), type(t) {  }
	virtual ~ParticleEvolver() {}
protected:
	ParticleProperty::EvolverType type{};
};
TYPE_MARCO(ParticleEvolver);

/** Changes the size of the particles over the particle lifetime. */
REFLECTION_TYPE(ParticleSize)
CLASS_API(ENGINE_API, ParticleSize : public ParticleEvolver, Fields)
{
    REFLECTION_BODY(ParticleSize);
	DECLARE_RTTI
	DECLARE_INITIAL
public:
	bool m_Use3DSize;
	bool m_UseScale;
	std::vector<Math::Vec3> m_InitSize;
public:
	ParticleSize(Object* pHost) : ParticleEvolver(pHost, ParticleProperty::EvolverType::Ev_Size) {}
	~ParticleSize() {}
};
TYPE_MARCO(ParticleSize);

/** Changes the color of the particles over the particle lifetime. */
REFLECTION_TYPE(ParticleColor)
CLASS_API(ENGINE_API, ParticleColor : public ParticleEvolver, Fields)
{
    REFLECTION_BODY(ParticleColor);
	DECLARE_RTTI
	DECLARE_INITIAL
private:
	bool m_UseMultiply;
	std::vector<Math::Vec4> m_InitColor;
public:
	ParticleColor(Object * pHost) : ParticleEvolver(pHost, ParticleProperty::EvolverType::Ev_Color){}
	~ParticleColor() {}
};
TYPE_MARCO(ParticleColor);

/** Rotates the particles over the particle lifetime. */
REFLECTION_TYPE(ParticleRotation)
CLASS_API(ENGINE_API, ParticleRotation : public ParticleEvolver, Fields)
{
	REFLECTION_BODY(ParticleRotation);
	DECLARE_RTTI
	DECLARE_INITIAL
private:
	bool m_Use3DRotation;
	bool m_UseRate;
public:
	ParticleRotation(Object* pHost) : ParticleEvolver(pHost, ParticleProperty::EvolverType::Ev_Rotation) {}
	~ParticleRotation() {}
};
TYPE_MARCO(ParticleRotation);

NS_JYE_END