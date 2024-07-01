#pragma once

#include "Component.h"

NS_JYE_BEGIN

class Scene;

REFLECTION_TYPE(ScriptComponent)
STRUCT_API(ENGINE_API, ScriptComponent : Component, WhiteListFields)
{
    REFLECTION_BODY(ScriptComponent);
    DECLARE_RTTI
	DECLARE_INITIAL
public:
    ScriptComponent(Object* pHost);
    ScriptComponent(Object* pHost, const std::string& luafile);
    virtual ~ScriptComponent();

protected:
    std::string m_luaFile;
};

NS_JYE_END