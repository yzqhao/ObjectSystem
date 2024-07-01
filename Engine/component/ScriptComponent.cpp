#include "ScriptComponent.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI(ScriptComponent, Component);
IMPLEMENT_INITIAL_BEGIN(ScriptComponent)
IMPLEMENT_INITIAL_END

ScriptComponent::ScriptComponent(Object* pHost) : Component(pHost)
{

}

ScriptComponent::ScriptComponent(Object* pHost, const std::string& luafile) : Component(pHost), m_luaFile(luafile)
{

}

ScriptComponent::~ScriptComponent()
{

}

NS_JYE_END