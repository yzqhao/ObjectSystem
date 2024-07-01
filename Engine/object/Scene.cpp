#include "Scene.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI(Scene, Object);
IMPLEMENT_INITIAL_BEGIN(Scene)
IMPLEMENT_INITIAL_END

Scene::Scene(Object* pHost) : Object(pHost), m_rootObject(nullptr)
{

}

Scene::Scene(const std::string& name) : Scene(nullptr)
{
    m_name = name;
    m_rootObject = CreateObject("root_node");
}

Scene::~Scene()
{
    SAFE_DELETE(m_rootObject);
}

GameObject* Scene::CreateObject(const std::string& objName)
{
    GameObject* node = _NEW GameObject(this);
    if (m_rootObject)
    {
        m_rootObject->AddChild(node);
    }
    m_gobjects[node->GetStaticID()] = node;
    node->SetName(objName);
    return node;
}

void Scene::DeleteGObject(GameObject* node)
{
    
}

NS_JYE_END