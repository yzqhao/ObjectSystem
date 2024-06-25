#pragma once

#include "Core/Object.h"
#include "../private/Define.h"

NS_JYE_BEGIN

REFLECTION_TYPE(Animatable)
CLASS_API(ENGINE_API, Animatable : public Object, Fields)
{
    REFLECTION_BODY(Animatable);
    DECLARE_RTTI
    DECLARE_INITIAL
public:
    Animatable();
    virtual ~Animatable();

    FORCEINLINE uint64 GetStaticID() const { return m_id; }

    void Awake();
    void Start();
    void Update(float dt);
    void LateUpdate(float dt);
    void Destroy();

protected:
    virtual void _OnAwake() {};
    virtual void _OnStart() {};
    virtual void _OnUpdate(float dt) {};
    virtual void _OnLateUpdate(float dt) {};
    virtual void _OnDestroy() {};
    virtual void _OnActiveChanged() {}

    META(Enable) uint64 m_id;
    META(Enable) bool m_isActive;
    bool m_isStarted;
    bool m_isAwaked;
};
TYPE_MARCO(Animatable);

NS_JYE_END