#include "ParticleComponent.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI(ParticleSystemSettings, Object);
IMPLEMENT_INITIAL_BEGIN(ParticleSystemSettings)
IMPLEMENT_INITIAL_END

IMPLEMENT_RTTI(ParticleComponent, Component);
IMPLEMENT_INITIAL_BEGIN(ParticleComponent)
IMPLEMENT_INITIAL_END

ParticleComponent::ParticleComponent(Object* pHost) : Component(pHost), m_Settings(nullptr)
{
    
}

ParticleComponent::~ParticleComponent()
{

}

void ParticleComponent::AddEvolver(ParticleProperty::EvolverType et)
{
    if (m_Evolvers[et] != NULL)
    {
        return;
    }

    switch (et)
    {
    case ParticleProperty::Ev_Size:
    {
        ParticleSize* newEvolver = new ParticleSize(this);
        m_Evolvers[et] = newEvolver;
        break;
    }
    case ParticleProperty::Ev_Color:
    {
        ParticleColor* newEvolver = new ParticleColor(this);
        m_Evolvers[et] = newEvolver;
        break;
    }
    case ParticleProperty::Ev_Rotation:
    {
        ParticleRotation* newEvolver = new ParticleRotation(this);
        m_Evolvers[et] = newEvolver;
        break;
    }
    default:
        break;
    }
}

NS_JYE_END