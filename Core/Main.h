
#pragma once

#include "Core.h"

NS_JYE_BEGIN

class Rtti;

class CORE_API Main
{
	typedef bool (*Function)();
public:
	static void AddInitialFunction(Function Func);
	static bool Initialize();
	static void AddTerminalFunction(Function Func);
	static bool Terminate();
private:
	Main();
	~Main();
	struct Element
	{
	public:
		Function Func {};
	};
	static std::vector<Element>* ms_pInitialArray;
	static std::vector<Element>* ms_pTerminalArray;
};

#include "MainMacro.h"

NS_JYE_END
