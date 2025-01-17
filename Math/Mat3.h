
#pragma once

#include "Vec3.h"

NS_JYE_BEGIN
REFLECTION_TYPE(Mat3)
class Serializer;
NS_JYE_END

NS_JYE_MATH_BEGIN

class Mat4;

CLASS_API(MATH_API, Mat3, Fields)
{
    REFLECTION_BODY(Mat3);
public:
#if defined(__REFLECTION_PARSER__)
    float a11, a12, a13;
    float a21, a22, a23;
    float a31, a32, a33;
#else
	union
	{
		struct
		{
			float a11, a12, a13;
			float a21, a22, a23;
			float a31, a32, a33;
		};
    	float m[9];
	};
#endif

	Mat3();
    Mat3(const Mat4& mat4);
    Mat3(float m11, float m12, float m13, float m21, float m22, float m23, 
           float m31, float m32, float m33);
    Mat3(const float* mat);
    Mat3(const Mat3& copy);
    ~Mat3();

    void multiply(const Mat3& mat);
    static void multiply(const Mat3& m1, const Mat3& m2, Mat3* dst);

	Mat3& Transpose();

    bool IsIdentity() const;
    void SetIdentity();
    float Determinant() const;
    Mat3 GetInversed() const;

	void Scale(float value);
	void Scale(const Vec3& s);

	const float* GetPtr() const { return &m[0]; }

    std::string toString() const;

    static const Mat3 ZERO;     
    static const Mat3 IDENTITY; 
};

inline Vec3& operator*=(Vec3& v, const Mat3& m)
{
    Vec3 temp(v.x * m.a11 + v.y * m.a21 + v.z * m.a31,
            v.x * m.a12 + v.y * m.a22 + v.z * m.a32,
            v.x * m.a13 + v.y * m.a23 + v.z * m.a33);
    v = temp;
    return v;
}

inline Vec3 operator*(const Vec3& v, const Mat3& m)
{
    return Vec3(v.x * m.a11 + v.y * m.a21 + v.z * m.a31,
                v.x * m.a12 + v.y * m.a22 + v.z * m.a32,
                v.x * m.a13 + v.y * m.a23 + v.z * m.a33);
}

NS_JYE_MATH_END