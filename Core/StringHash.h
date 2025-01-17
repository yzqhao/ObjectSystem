
#pragma once

#include "Core.h"

NS_JYE_BEGIN

class CORE_API StringHash
{
	friend class StringManager;
public:
	inline const char* GetBuffer() const { return m_String.data(); }
	inline const std::string& GetString() const { return m_String; }
	inline unsigned int GetLength() const { return m_String.length(); }
	inline unsigned int GetID() const { return m_uiID; }

	StringHash() {}

protected:
	StringHash(unsigned id, const char* pchar) : m_uiID(id), m_String(pchar) {}
	unsigned m_uiID{};
	std::string m_String;
};

class StringManager
{
public:
	~StringManager();
	static StringManager& GetInstance()
	{
		static StringManager g_Initial;
		return g_Initial;
	}

	StringHash* GetOrCreateName(const char* name);
	StringHash* GetOrCreateName(const std::string& name);
private:
	StringManager();
	StringHash* CheckIsHave(unsigned uid);
	
	std::unordered_map<unsigned, StringHash*> m_strings;
};

NS_JYE_END
