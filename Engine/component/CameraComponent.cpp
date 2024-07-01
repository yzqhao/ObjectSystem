#include "CameraComponent.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI(CameraComponent, Component);
IMPLEMENT_INITIAL_BEGIN(CameraComponent)
IMPLEMENT_INITIAL_END

CameraComponent::CameraComponent(Object* pHost) : Component(pHost)
{

}

CameraComponent::~CameraComponent()
{

}

NS_JYE_END