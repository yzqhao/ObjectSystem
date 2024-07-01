#include "GameObject.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI(GameObject, Animatable);
IMPLEMENT_INITIAL_BEGIN(GameObject)
IMPLEMENT_INITIAL_END

GameObject::GameObject(Object* pHost)  : Animatable(pHost), m_RootNode(nullptr)
{

}

GameObject::~GameObject()
{

}

bool GameObject::AddChild(GameObject* actor)
{
    if (NULL != actor
        && std::find(m_children.begin(), m_children.end(), actor) == m_children.end())
    {
        actor->_SetFather(this);
        m_children.push_back(actor);
        return true;
    }

    return false;
}

bool GameObject::DetachNode(GameObject* actor)
{
    return false;
}

Component* GameObject::CreateComponent(const std::string& compenent_type_name)
{
    for (const auto& component : m_components)
    {
        if (component->GetType().GetName() == compenent_type_name)
        {
            return component;
        }
    }

    Component* com = static_cast<Component*>(CreateInstance(compenent_type_name, this));
    m_components.push_back(com);

    return com;
}

Component* GameObject::GetComponent(const std::string& compenent_type_name)
{
    for (const auto& component : m_components)
    {
        if (component->GetType().GetName() == compenent_type_name)
        {
            return component;
        }
    }

    return nullptr;
}

NS_JYE_END