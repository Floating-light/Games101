#pragma once
#include "vec3.h"

// (1) calculate the ray from the eye to the pixel, 
// (2) determine which objects the ray intersects, and 
// (3) compute a color for that intersection point. 

class ray
{
public:
	ray() { };
	ray(const point3& origin, const vec3& direction)
		: orig(origin), dir(direction)
	{

	}

	point3 origin() const { return orig; }
	vec3 direction() const { return dir; }
	point3 at(double t) const
	{
		return orig+ t * dir;
	}
public:
	point3 orig;
	vec3 dir;
};