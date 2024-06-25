#pragma once

#include "Component.h"

NS_JYE_BEGIN

class Scene;

REFLECTION_TYPE(TransformComponent)
STRUCT_API(ENGINE_API, TransformComponent : Component, WhiteListFields)
{
    REFLECTION_BODY(TransformComponent);
    DECLARE_RTTI
	DECLARE_INITIAL
public:
    TransformComponent();
    virtual ~TransformComponent();

protected:

};

NS_JYE_END