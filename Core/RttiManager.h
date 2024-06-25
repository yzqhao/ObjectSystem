
#pragma once

#include "Rtti.h"

NS_JYE_BEGIN


class CORE_API RttiManager
{
public:
	RttiManager();
	~RttiManager();
	static RttiManager* Instance();

	void RegisterClass(const std::string& name, Rtti* rtti);
	const Rtti* GetRttiByName(const std::string& RttiName);
	const RttiInfoIn* GetRttInfoByName(const std::string& RttiName);
	void GetChildrenName(const std::string& name, std::vector<std::string>& outChildrenNames);

	void Initlize();
	void Destory();

private:
	std::unordered_map<std::string, RttiInfoIn*>	m_mapRttiInfo;
	std::unordered_map<std::string, Rtti*> m_mapRtti;
};

NS_JYE_END
