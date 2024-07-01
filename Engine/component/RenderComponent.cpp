#include "RenderComponent.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI(RenderComponent, Component);
IMPLEMENT_INITIAL_BEGIN(RenderComponent)
IMPLEMENT_INITIAL_END

RenderComponent::RenderComponent(Object* pHost) : Component(pHost)
{

}

RenderComponent::~RenderComponent()
{

}

NS_JYE_END