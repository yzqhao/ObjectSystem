#include "Component.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI_NoCreateFun(Component, Animatable);
IMPLEMENT_INITIAL_NO_CLASS_FACTORY_BEGIN(Component)
IMPLEMENT_INITIAL_NO_CLASS_FACTORY_END

Component::Component(Object* go) : Animatable(go)
{

}

Component::~Component()
{

}

NS_JYE_END