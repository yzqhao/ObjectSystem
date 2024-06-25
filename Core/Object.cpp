
#include "Object.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI_NoParent_NoCreateFun(Object)
std::unordered_map<std::string, Object::FactoryFunction> Object::ms_ClassFactory;
IMPLEMENT_INITIAL_NO_CLASS_FACTORY_BEGIN(Object)
IMPLEMENT_INITIAL_NO_CLASS_FACTORY_END

Object::Object() 
{

}

Object::~Object()
{
	
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

NS_JYE_END
