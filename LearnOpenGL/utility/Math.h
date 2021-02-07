#pragma once 

#include "CoreType.h"

class RMath
{
public:
	/**
	* @param Up 不是指相机真正的上面, 用这个来算right
	*/
	static Matrix4 ViewTransform(const Vector3D& Eye, const Vector3D& Target, const Vector3D& Up);
	static Matrix4 PerspectiveTransform(float fov, float aspect, float znear, float zfar);
	static Vector3D Cross(const Vector3D& v1, const Vector3D& v2);
	static float Dot(const Vector3D& v1, const Vector3D& v2);
	static Vector3D Normalize(const Vector3D& v);
	static float Radians(float Degrees);
	static float Degrees(float Radians);
	static float Clamp(float a, float min, float max);
};