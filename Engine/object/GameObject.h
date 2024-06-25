#pragma once

#include "Core/Object.h"
#include "../private/Define.h"
#include "../component/Component.h"

NS_JYE_BEGIN

class Scene;

REFLECTION_TYPE(GameObject)
CLASS_API(ENGINE_API, GameObject : public Animatable, WhiteListFields)
{
    REFLECTION_BODY(GameObject);
    DECLARE_RTTI
	DECLARE_INITIAL
public:
    GameObject();
    GameObject(Scene* sce);
    virtual ~GameObject();

    FORCEINLINE void SetName(const std::string & name) { m_name = name; }

    bool AddChild(GameObject* node);
    bool DetachNode(GameObject* actor);

    Component* CreateComponent(const std::string& compenent_type_name);
    Component* GetComponent(const std::string& compenent_type_name);

    template<typename TComponent> TComponent* TryGetComponent();
    template<typename TComponent> const TComponent* TryGetComponentConst() const;
    template<typename TComponent> TComponent* CreateComponent();
    template<typename TComponent> void RemoveComponent();

protected:

    void _SetFather(GameObject* root)
    {
        m_RootNode = root;
    }

    META(Enable) Scene* m_pHostScene;
    META(Enable) std::string m_name;
    META(Enable) uint64 m_MaskLayer;
    META(Enable) GameObject* m_RootNode;	//¸¸½Úµã

    META(Enable) std::vector<Component*> m_components;
    META(Enable) std::vector<GameObject*> m_children;
};
TYPE_MARCO(GameObject);

template<typename TComponent>
TComponent* GameObject::TryGetComponent()
{
    for (auto& component : m_components)
    {
        if (component->GetType().GetName() == TComponent::ms_Type.GetName())
        {
            return static_cast<TComponent*>(component.GetEObject());
        }
    }

    return nullptr;
}

template<typename TComponent>
const TComponent* GameObject::TryGetComponentConst() const
{
    for (const auto& component : m_components)
    {
        if (component->GetType().GetName() == TComponent::ms_Type.GetName())
        {
            return static_cast<const TComponent*>(component.GetEObject());
        }
    }
    return nullptr;
}

template<typename TComponent>
TComponent* GameObject::CreateComponent()
{
    return static_cast<TComponent*>(CreateComponent(TComponent::ms_Type.GetName()));
}

template<typename TComponent>
void GameObject::RemoveComponent()
{
    return static_cast<TComponent*>(RemoveComponent(TComponent::ms_Type.GetName()));
}

NS_JYE_END