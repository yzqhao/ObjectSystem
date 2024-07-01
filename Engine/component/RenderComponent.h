#pragma once

#include "Component.h"

NS_JYE_BEGIN

class Scene;

class ENGINE_API RenderComponent : public Component
{
    DECLARE_RTTI
	DECLARE_INITIAL
public:
    RenderComponent(Object* pHost);
    virtual ~RenderComponent();

protected:

};

NS_JYE_END