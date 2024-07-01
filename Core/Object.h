
#pragma once

#include "Rtti.h"
#include "Type.h"
#include "../Meta/reflection.h"
#include "Main.h"

NS_JYE_BEGIN

class FastObjectManager;

REFLECTION_TYPE(Object)
CLASS_API(CORE_API, Object, Fields)
{
	REFLECTION_BODY(Object);
    DECLARE_RTTI;
    DECLARE_INITIAL_NO_CLASS_FACTORY;

    using FactoryFunction = Object * (*)(Object* host);
    friend class FastObjectManager;
public:
	Object(Object* pHost);
	virtual ~Object();

    bool IsSameType(const Object * pObject)const;
    bool IsDerived(const Object * pObject)const;
    bool IsSameType(const Rtti & Type)const;
    bool IsDerived(const Rtti & Type)const;

    static FastObjectManager& GetObjectManager();
    static Object* CreateInstance(const std::string& sRttiName, Object * host = nullptr);
    static Object* CreateInstance(const Rtti& Rtti, Object * host = nullptr);

protected:
    Object* _GetOwner() { return m_owner; }
    Object* _GetOwner() const { return m_owner; }

	static std::unordered_map<std::string, FactoryFunction> ms_ClassFactory;	// 只有Object类持有

    Object* m_owner;
};
TYPE_MARCO(Object);

class CORE_API FastObjectManager
{
public:
    FastObjectManager();
    ~FastObjectManager();
    void AddObject(Object* p);
    void DeleteObject(Object* p);
    bool IsClear();
    void Dump();
    uint GetObjectNum();
protected:
    std::unordered_set<Object*> ObjectHashTree;
    uint m_uiObjectNum;
};

template <class T> T* StaticCast(Object* pkObj) { return (T*)pkObj; }
template <class T> const T* StaticCast(const Object* pkObj) { return (const T*)pkObj; }
template<class T> T* DynamicCast(Object* pObj) { return pObj && pObj->IsDerived(T::ms_Type) ? (T*)pObj : nullptr; }
template<class T> const T* DynamicCast(const Object* pObj) { return pObj && pObj->IsDerived(T::ms_Type) ? (const T*)pObj : nullptr; }


NS_JYE_END
