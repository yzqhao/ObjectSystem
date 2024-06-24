
#pragma once

#include "Vec3.h"

NS_JYE_BEGIN
REFLECTION_TYPE(Ray)
class Serializer;
NS_JYE_END

NS_JYE_MATH_BEGIN

class AABB;

CLASS_API(MATH_API, Ray, Fields)
{
    REFLECTION_BODY(Ray);
public:     
    Vec3 origin;   
    Vec3 direction;
public:
    Ray() {}
    Ray(const Vec3& origin, const Vec3& direction) : origin(origin), direction(direction) {}

	void SetRayOrigin(const Vec3& ori) { origin = ori; }
	void SetRayDirection(const Vec3& dir) { direction = dir; }
	const Vec3& GetRayOrigin() const { return origin; }
	const Vec3& GetRayDirection() const { return direction; }
	bool Intersect(const Math::AABB& box) const;
};

NS_JYE_MATH_END
