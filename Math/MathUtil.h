
#pragma once

#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Mat4.h"
#include "Quaternion.h"
#include "AABB.h"
#include "Ray.h"
#include "Sphere.h"

NS_JYE_MATH_BEGIN

namespace MathUtil
{
	MATH_API FORCEINLINE unsigned short FloatToHalf(float Value);
	MATH_API FORCEINLINE float HalfToFloat(unsigned short Value);
	MATH_API FORCEINLINE unsigned int CompressUnitFloat(float f, unsigned int Bit = 16);	//f must [0,1]
	MATH_API FORCEINLINE unsigned int CompressFloat(float f, float Max, float Min, unsigned int Bit = 16);
	MATH_API FORCEINLINE float DecompressUnitFloat(unsigned int quantized, unsigned int Bit = 16);
	MATH_API FORCEINLINE float DecompressFloat(unsigned int quantized, float Max, float Min, unsigned int Bit = 16);
	// ≤Â÷µVec2
	MATH_API Vec2 Lerp(const Vec2& v1, const Vec2& v2, float t);
	// ≤Â÷µVec3
	MATH_API Vec3 Lerp(const Vec3& v1, const Vec3& v2, float t);
	// ≤Â÷µVec4
	MATH_API Vec4 Lerp(const Vec4& v1, const Vec4& v2, float t);
};

#include "MathUtil.inl"

NS_JYE_MATH_END
