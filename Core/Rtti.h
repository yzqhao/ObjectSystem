
#pragma once

#include "Core.h"

NS_JYE_BEGIN

class Object;

class CORE_API Rtti
{
    friend class Object;
	using CreateObjectFun = Object*(*)(Object* host);
public:
	Rtti(const char* pcRttiName, Rtti *pBase, CreateObjectFun COF);
	~Rtti();

	inline const std::string &GetName()const {return m_cRttiName;}
	inline unsigned GetNameID() const { return m_nameID; }
	inline Rtti* GetBase()const { return m_pBase; }
	inline bool IsSameType(const Rtti &Type) const {return  (&Type == this);}

	bool IsDerived(const Rtti& Type) const;

private:
	std::string	m_cRttiName;
	unsigned m_nameID;
	Rtti*	m_pBase;
	CreateObjectFun m_CreateFun;
};

struct CORE_API RttiInfoIn
{
	RttiInfoIn(Rtti* pcur, Rtti* pbase) : cur(pcur), baser(pbase) {}

	Rtti* cur;
	Rtti* baser;
	std::vector<RttiInfoIn*> children;
};

//////////////////////////////////////////////////////////////////////////////////////
//						RTTI 萃取器
// 返回一个Object类型真正的类型
//////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct TObjectTraits
{
};

#include "RttiMacro.h"

NS_JYE_END
