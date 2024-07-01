#include "Animatable.h"

NS_JYE_BEGIN

IMPLEMENT_RTTI_NoCreateFun(Animatable, Object);

Animatable::Animatable(Object* pHost) : Object(pHost), m_id(0), m_isActive(true), m_isStarted(false), m_isAwaked(false)
{

}

Animatable::~Animatable()
{

}


void Animatable::Awake()
{
    m_isAwaked = true;
    _OnAwake();
}

void Animatable::Start()
{
    m_isStarted = true;
    _OnStart();
}

void Animatable::Update(float dt)
{
    
}

void Animatable::LateUpdate(float dt)
{
    
}

void Animatable::Destroy()
{
    _OnDestroy();
}

NS_JYE_END