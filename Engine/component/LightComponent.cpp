#include "LightComponent.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI(LightComponent, Component);
IMPLEMENT_INITIAL_BEGIN(LightComponent)
IMPLEMENT_INITIAL_END

LightComponent::LightComponent(Object* pHost) : Component(pHost)
{

}

LightComponent::~LightComponent()
{

}

NS_JYE_END