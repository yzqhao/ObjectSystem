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
    Component();
    Component(GameObject* go);
    virtual ~Component();

    GameObject* GetParentObject() { return m_Node; }
    const GameObject* GetParentObject() const { return m_Node; }

protected:
    META(Enable) GameObject* m_Node;
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