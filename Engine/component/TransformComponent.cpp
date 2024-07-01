#include "TransformComponent.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI(TransformComponent, Component);
IMPLEMENT_INITIAL_BEGIN(TransformComponent)
IMPLEMENT_INITIAL_END

TransformComponent::TransformComponent(Object* pHost) : Component(pHost)
{

}

TransformComponent::~TransformComponent()
{

}

NS_JYE_END