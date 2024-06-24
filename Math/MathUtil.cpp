#include "MathUtil.h"

NS_JYE_MATH_BEGIN

Vec2 MathUtil::Lerp(const Vec2& v1, const Vec2& v2, float t)
{
	return std::move(Math::Vec2(Math::Lerp(v1.x, v2.x, t), Math::Lerp(v1.y, v2.y, t)));
}

Vec3 MathUtil::Lerp(const Vec3& v1, const Vec3& v2, float t)
{
	return std::move(Math::Vec3(Math::Lerp(v1.x, v2.x, t), Math::Lerp(v1.y, v2.y, t), Math::Lerp(v1.z, v2.z, t)));
}

Vec4 MathUtil::Lerp(const Vec4& v1, const Vec4& v2, float t)
{
	return std::move(Math::Vec4(Math::Lerp(v1.x, v2.x, t), Math::Lerp(v1.y, v2.y, t), Math::Lerp(v1.z, v2.z, t), Math::Lerp(v1.w, v2.w, t)));
}

NS_JYE_MATH_END
