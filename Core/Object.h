
#pragma once

#include "Rtti.h"
#include "Type.h"
#include "../Meta/reflection.h"
#include "Main.h"

NS_JYE_BEGIN

REFLECTION_TYPE(Object)
CLASS_API(CORE_API, Object, Fields)
{
	REFLECTION_BODY(Object);
    DECLARE_RTTI;
    DECLARE_INITIAL_NO_CLASS_FACTORY;

	using FactoryFunction = Object * (*)(Object* host);
public:
	Object();
	virtual ~Object();

    bool IsSameType(const Object * pObject)const;
    bool IsDerived(const Object * pObject)const;
    bool IsSameType(const Rtti & Type)const;
    bool IsDerived(const Rtti & Type)const;

    static Object* CreateInstance(const std::string& sRttiName, Object * host = nullptr);
    static Object* CreateInstance(const Rtti& Rtti, Object * host = nullptr);

protected:
	static std::unordered_map<std::string, FactoryFunction> ms_ClassFactory;	// 只有Object类持有
};
TYPE_MARCO(Object);

NS_JYE_END
