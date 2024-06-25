#pragma once

#include "Engine/private/Define.h"

NS_JYE_BEGIN

namespace ParticleProperty
{
	enum ParticleSimulationSpace
	{
		Local = 1,
		World
	};
	/** Possible orientations when rendering billboard particles. */
	enum ParticleOrientation
	{
		ViewPlane = 1,
		ViewPosition,
		Axis,
		Velocity,
		AxisLocal,
	};
	/** Determines how to sort particles before rendering. */
	enum ParticleSortMode
	{
		None = 1,
		Distance,
		OldToYoung,
		YoungToOld
	};
	enum ParticleRenderMode
	{
		Billboard = 1,
		Mesh,
		Stretched_Billboard
	};
	enum State
	{
		Uninitialized = 0,
		Stopped,
		Paused,
		Playing
	};
	enum ParticleNoiseMode
	{
		NN_LOW = 1,
		NN_Medium,
		NN_High,
		NN_ExHigh
	};
	enum EvolverType
	{
		Ev_Gravity = 1,
		Ev_Force,
		Ev_Rotation,
		Ev_Orbit,
		Ev_Velocity,
		Ev_Size,
		Ev_Color,
		Ev_Collisions,
		Ev_TextureAnimation,
		Ev_SpeedModifier,
		Ev_VectorField,
		Ev_Noise,
		Ev_InheritVelocity,
		Ev_LimitVelocity,
	};

	enum EmitterType
	{
		Em_Line = 1,
		Em_Box,
		Em_Cone,
		Em_Circle,
		Em_Rect,
		Em_Sphere,
		Em_HemiSphere,
		Em_Mesh
	};
	/** Types of emission modes. */
	enum ParticleEmissionModeType
	{
		/** Position will be picked randomly on a shape. */
		EM_Random = 1,

		/** Positions will loop around the shape in a predictable fashion. */
		EM_Loop,

		/** Similar to Loop, except the order will be reversed when one loop iteration finishes. */
		EM_PingPong,

		/**
		* All particles spawned on the shape at some instant (usually a frame) will be spread around the shape equally.
		*/
		EM_Spread
	};
	enum PropertyDistributionType
	{
		/** The distribution is a costant value. */
		PDT_Constant,
		/** The distribution is a random value in a specified constant range. */
		PDT_RandomRange,
		/** The distribution is a time-varying value. */
		PDT_Curve,
		/** The distribution is a random value in a specified time-varying range. */
		PDT_RandomCurveRange
	};

	enum SubEmitterTriggerType
	{
		STT_None = 1,
		STT_Born,
		STT_Collision,
		STT_Death,
	};

	enum SubEmitterInheritType
	{
		SEIT_COLOR = 1 << 0UL,
		SEIT_SIZE = 1 << 1UL,
		SEIT_ROTATION = 1 << 2UL,
		SEIT_LIFRTIME = 1 << 3UL,
	};

	enum TrailTextureMode
	{
		Tile = 1,
		Distribute_Per_Segment,
		Repeat_Per_Segment,
	};


	enum VectorFieldLevel
	{
		VL_LOW = 1,
		VL_MID,
		VL_HIGH,
	};

	enum InheritVelocityMode
	{
		IVM_Initial = 1,
		IVM_Current,
	};

	enum ParticleSimulateStage
	{
		PSS_Emit,
		PSS_Update,
	};

	enum ParticleModuleVersion
	{
		ParticleDistribution_Version = 1,
		ColorDistribution_Version = 1,
		//version 1 原始版本
		//version 2 将InitialRotation和rotation over life time的旋转从弧度改为角度 & 增加rate旋转速度属性
		//version 3	增加inherit velocity和limit velocity & 新出生的粒子在刚被发射后增加postsimulate且不再多做一组simulate & size\color over lifetime 增加scale属性，导致burst模式也需要做presimulate
		ParticleSetting_Version = 3,
		ParticleForce_Version = 1,
	};

	static bool IsPriority(const EvolverType et)
	{
		switch (et)
		{
		case ParticleProperty::Ev_Gravity:
		case ParticleProperty::Ev_Force:
		case ParticleProperty::Ev_Rotation:
		case ParticleProperty::Ev_Orbit:
		case ParticleProperty::Ev_Velocity:
		case ParticleProperty::Ev_Size:
		case ParticleProperty::Ev_Color:
		case ParticleProperty::Ev_InheritVelocity:
			return true;
		case ParticleProperty::Ev_TextureAnimation:
		case ParticleProperty::Ev_Collisions:
		case ParticleProperty::Ev_SpeedModifier:
		case ParticleProperty::Ev_VectorField:
		case ParticleProperty::Ev_Noise:
		case ParticleProperty::Ev_LimitVelocity:
		default:
			break;
		}
		return false;
	}
}

NS_JYE_END