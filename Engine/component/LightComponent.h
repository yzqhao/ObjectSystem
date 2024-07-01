#pragma once

#include "Component.h"

NS_JYE_BEGIN

class Scene;

class ENGINE_API LightComponent : public Component
{
    DECLARE_RTTI
	DECLARE_INITIAL
public:
    LightComponent(Object* pHost);
    virtual ~LightComponent();

protected:

};

NS_JYE_END