#pragma once

#include "Animatable.h"
#include "Core/Serializer.h"

NS_JYE_BEGIN

class GameObject;

#define SERIALIZER_COMPONENT_POINT \
    public: \
        virtual Json serializerComponentPoint() const { return Serializer::writeObjectPointer(this); }

REFLECTION_TYPE(Component)
CLASS_API(ENGINE_API, Component : public Animatable, WhiteListFields)
{
    REFLECTION_BODY(Component);
    DECLARE_RTTI
	DECLARE_INITIAL
public:
    Component(Object* go);
    virtual ~Component();

    GameObject* GetParentObject() { return (GameObject*)_GetOwner(); }
    const GameObject* GetParentObject() const { return (GameObject*)_GetOwner(); }

protected:
};
TYPE_MARCO(Component);

/*
template<>
inline Json Serializer::writeObjectPointer(const Component* instance)
{
    return instance->serializerComponentPoint();
}
*/
NS_JYE_END