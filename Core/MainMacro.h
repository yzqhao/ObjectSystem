#pragma  once
// 不要单独包含此文件
/********************************************************************************/
#if defined(__REFLECTION_PARSER__)
#define DECLARE_INITIAL
#else
#define DECLARE_INITIAL \
public: \
		static bool RegisterMainFactory(); \
public: \
		static bool InitialClassFactory(); \
		static Object* FactoryFunc(Object* host); \
		static bool ms_bRegisterMainFactory; \
		static bool InitialProperty(Rtti *); \
		static bool TerminalProperty();
#endif
/********************************************************************************/
#define IMPLEMENT_INITIAL_BEGIN(classname) \
	static bool gs_bStreamRegistered_##classname= classname::RegisterMainFactory (); \
	bool classname::ms_bRegisterMainFactory = false; \
	bool classname::InitialClassFactory() \
	{ \
		ms_ClassFactory.insert({ms_Type.GetName(), FactoryFunc}); \
		return 1; \
	} \
	Object* classname::FactoryFunc(Object* host) \
	{ \
		return _NEW classname(host);\
	} \
	bool classname::RegisterMainFactory() \
	{ \
		if (!ms_bRegisterMainFactory) \
		{  

/********************************************************************************/
#define IMPLEMENT_INITIAL_NO_FACTORY_BEGIN(classname) \
	static bool gs_bStreamRegistered_##classname= classname::RegisterMainFactory (); \
	bool classname::ms_bRegisterMainFactory = false; \
	bool classname::InitialClassFactory() \
	{ \
		ms_ClassFactory.insert({ms_Type.GetName(), FactoryFunc}); \
		return 1; \
	} \
	bool classname::RegisterMainFactory() \
	{ \
		if (!ms_bRegisterMainFactory) \
		{  

/********************************************************************************/
#define IMPLEMENT_INITIAL_END \
			Main::AddInitialFunction(InitialClassFactory); \
			ms_bRegisterMainFactory = true; \
		} \
		return ms_bRegisterMainFactory; \
	}
/********************************************************************************/
#define DECLARE_INITIAL_ONLY \
public: \
		static bool RegisterMainFactory(); \
public: \
		static bool ms_bRegisterMainFactory;
/********************************************************************************/
#define IMPLEMENT_INITIAL_ONLY_BEGIN(classname) \
	static bool gs_bStreamRegistered_##classname= classname::RegisterMainFactory (); \
	bool classname::ms_bRegisterMainFactory = false; \
	bool classname::RegisterMainFactory() \
	{ \
		if (!ms_bRegisterMainFactory) \
		{  

/********************************************************************************/
#define IMPLEMENT_INITIAL_ONLY_END \
			ms_bRegisterMainFactory = true; \
		} \
		return ms_bRegisterMainFactory; \
	}

/********************************************************************************/
#define DECLARE_INITIAL_NO_CLASS_FACTORY \
public: \
		static bool RegisterMainFactory(); \
public: \
		static bool ms_bRegisterMainFactory; \
		static bool InitialProperty(Rtti *); \
		static bool TerminalProperty();
/********************************************************************************/
#define IMPLEMENT_INITIAL_NO_CLASS_FACTORY_BEGIN(classname) \
	static bool gs_bStreamRegistered_##classname= classname::RegisterMainFactory (); \
	bool classname::ms_bRegisterMainFactory = false; \
	bool classname::RegisterMainFactory() \
	{ \
		if (!ms_bRegisterMainFactory) \
		{  

/********************************************************************************/
#define IMPLEMENT_INITIAL_NO_CLASS_FACTORY_END \
			ms_bRegisterMainFactory = true; \
		} \
		return ms_bRegisterMainFactory; \
	}
/********************************************************************************/
#define	ADD_INITIAL_FUNCTION(function_name)\
	Main::AddInitialFunction(function_name); 
/********************************************************************************/
#define	ADD_TERMINAL_FUNCTION(function_name)\
	Main::AddTerminalFunction(function_name);
