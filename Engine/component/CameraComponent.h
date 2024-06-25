#pragma once

#include "Component.h"

NS_JYE_BEGIN

class ENGINE_API CameraComponent : public Component
{
    DECLARE_RTTI
	DECLARE_INITIAL
public:
    CameraComponent();
    virtual ~CameraComponent();

protected:

};

NS_JYE_END