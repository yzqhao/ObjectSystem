
#include "Rtti.h"
#include "RttiManager.h"
#include "StringHash.h"

NS_JYE_BEGIN

Rtti::Rtti(const char* pcRttiName, Rtti* pBase, CreateObjectFun COF) : m_cRttiName(pcRttiName)
{
	m_pBase = pBase;
	m_nameID = StringManager::GetInstance().GetOrCreateName(m_cRttiName)->GetID();
	m_CreateFun = COF;
	RttiManager::Instance()->RegisterClass(m_cRttiName, this);
}

Rtti::~Rtti()
{
	m_pBase = nullptr;
}

bool Rtti::IsDerived(const Rtti &Type) const
{
	const Rtti * pTemp = this;
	while(!pTemp->IsSameType(Type))
	{
		if(pTemp->m_pBase)
		{
			pTemp = pTemp->m_pBase;
		}
		else
		{
			return false;
		}
	}
	return true;
}

NS_JYE_END
