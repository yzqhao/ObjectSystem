#pragma once

#include "Component.h"
#include "ParticleProperty.h"
#include "ParticleEvolver.h"

NS_JYE_BEGIN


REFLECTION_TYPE(ParticleSystemSettings)
STRUCT_API(ENGINE_API, ParticleSystemSettings : public Object, Fields)
{
    REFLECTION_BODY(Component);
    DECLARE_RTTI
	DECLARE_INITIAL

	bool gpuSimulation;
	ParticleProperty::ParticleSimulationSpace simulationSpace;
	ParticleProperty::ParticleOrientation orientation;

	bool orientationLockY;
	Math::Vec3 orientationPlaneNormal;

	ParticleProperty::ParticleSortMode sortMode;

	float duration;

	bool isLooping;

	uint32_t maxParticles;

	bool useAutomaticSeed;

	uint32_t manualSeed;

	bool useAutomaticBounds;

	Math::AABB customBounds;

	/** Determines how is each particle represented on the screen. */
	ParticleProperty::ParticleRenderMode renderMode;

	float stretchSpeedScale;
	float stretchLengthScale;

	bool preWarm;
	float startDelay;

	ParticleSystemSettings()
		: gpuSimulation(false)
		, simulationSpace(ParticleProperty::ParticleSimulationSpace::World)
		, orientation(ParticleProperty::ParticleOrientation::ViewPlane)
		, orientationLockY(false)
		, orientationPlaneNormal(Math::Vec3(0.0, 0.0, 1.0))
		, sortMode(ParticleProperty::ParticleSortMode::None)
		, duration(5.0f)
		, isLooping(true)
		, maxParticles(100)
		, useAutomaticSeed(true)
		, manualSeed(rand())
		, useAutomaticBounds(true)
		, renderMode(ParticleProperty::ParticleRenderMode::Billboard)
		, stretchSpeedScale(0.0)
		, stretchLengthScale(1.0)
		, preWarm(false)
		, startDelay(0.0)
	{

	}
};

REFLECTION_TYPE(ParticleComponent)
CLASS_API(ENGINE_API, ParticleComponent : public Component, WhiteListFields)
{
    REFLECTION_BODY(ParticleComponent);
    DECLARE_RTTI
	DECLARE_INITIAL
public:
    ParticleComponent();
    virtual ~ParticleComponent();

    void AddEvolver(ParticleProperty::EvolverType et);

protected:
    META(Enable) ParticleSystemSettings m_Settings;
	META(Enable) std::unordered_map<ParticleProperty::EvolverType, ParticleEvolver*> m_Evolvers;
};

NS_JYE_END