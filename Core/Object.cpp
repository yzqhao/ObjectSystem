
#include "Object.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI_NoParent_NoCreateFun(Object)
std::unordered_map<std::string, Object::FactoryFunction> Object::ms_ClassFactory;
IMPLEMENT_INITIAL_NO_CLASS_FACTORY_BEGIN(Object)
IMPLEMENT_INITIAL_NO_CLASS_FACTORY_END

Object::Object(Object* pHost) : m_owner(pHost)
{
    GetObjectManager().AddObject(this);
}

Object::~Object()
{
    GetObjectManager().DeleteObject(this);
}

bool Object::IsSameType(const Object* pObject) const
{
    return pObject && GetType().IsSameType(pObject->GetType());
}

bool Object::IsDerived(const Object* pObject)const
{
    return pObject && GetType().IsDerived(pObject->GetType());
}

bool Object::IsSameType(const Rtti& Type)const
{
    return GetType().IsSameType(Type);
}

bool Object::IsDerived(const Rtti& Type)const
{
    return GetType().IsDerived(Type);
}

Object* Object::CreateInstance(const std::string& sRttiName, Object* host)
{
    auto i = ms_ClassFactory.find(sRttiName);
    if (i == ms_ClassFactory.end())
        return NULL;

    Object* pObject = i->second(host);
    return pObject;
}

Object* Object::CreateInstance(const Rtti& Rtti, Object* host)
{
    Object* pObject = (Rtti.m_CreateFun)(host);
    return pObject;
}

//
// FastObjectManager
//

FastObjectManager& Object::GetObjectManager()
{
    static FastObjectManager ms_ObjectManager;
    return  ms_ObjectManager;
}

FastObjectManager::FastObjectManager()
{
    m_uiObjectNum = 0;
    ObjectHashTree.reserve(300);
}

FastObjectManager::~FastObjectManager()
{

}

void FastObjectManager::AddObject(Object* p)
{
    JY_ASSERT(p);
    ObjectHashTree.insert(p);
    m_uiObjectNum++;
}

void FastObjectManager::DeleteObject(Object* p)
{
    JY_ASSERT(p);
    ObjectHashTree.erase(p);
    m_uiObjectNum--;
}

bool FastObjectManager::IsClear()
{
    return m_uiObjectNum == 0;
}

void FastObjectManager::Dump()
{
    std::unordered_map<std::string_view, int> objectHash;
    for (auto it : ObjectHashTree)
    {
        objectHash[it->GetTypeName()]++;
    }
    for (auto it : objectHash)
    {
        printf("%s num : %d\n", it.first.data(), it.second);
    }
}

uint FastObjectManager::GetObjectNum()
{
    return m_uiObjectNum;
}

NS_JYE_END
