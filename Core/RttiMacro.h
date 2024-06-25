#pragma  once
// 不要单独包含此文件
#define DECLARE_RTTI \
public:\
	virtual Object* Duplicate() const; \
	virtual const Rtti & GetType()const{return ms_Type;}\
	virtual const unsigned GetTypeID()const{return ms_Type.GetNameID();}\
	virtual const std::string& GetTypeName()const{return ms_Type.GetName();}\
	static Rtti ms_Type;\
	static Rtti& RTTI() { return ms_Type; }\
/********************************************************************************/

#define IMPLEMENT_RTTI(classname, baseclassname)\
	Object* classname::Duplicate() const { return _NEW classname(*this); } \
	Rtti classname::ms_Type((#classname),&baseclassname::ms_Type, classname::FactoryFunc); \

/********************************************************************************/
#define IMPLEMENT_RTTI_NoCreateFun(classname,baseclassname)\
	Object* classname::Duplicate() const { JY_ASSERT(false); return NULL; } \
	Rtti classname::ms_Type((#classname),&baseclassname::ms_Type,NULL); \
/********************************************************************************/
#define IMPLEMENT_RTTI_NoParent(classname)\
	Object* classname::Duplicate() const { JY_ASSERT(false); return NULL; } \
	Rtti classname::ms_Type((#classname),NULL,classname::FactoryFunc); \

/********************************************************************************/
#define IMPLEMENT_RTTI_NoParent_NoCreateFun(classname)\
	Object* classname::Duplicate() const { JY_ASSERT(false); return NULL; } \
	Rtti classname::ms_Type((#classname),NULL,NULL); \

/********************************************************************************/
