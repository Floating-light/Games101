//
// Created by Göksu Güvendiren on 2019-05-14.
//

#include "Scene.hpp"


void Scene::buildBVH() {
	printf(" - Generating BVH...\n\n");
	this->bvh = new BVHAccel(objects, 1, BVHAccel::SplitMethod::NAIVE);
}
Intersection Scene::intersect(const Ray& ray)const
{
	return this->bvh->Intersect(ray);
}
void Scene::sampleLight(Intersection& pos, float& pdf) const
{
	float emit_area_sum = 0;
	for (uint32_t k = 0; k < objects.size(); ++k) {
		if (objects[k]->hasEmit()) {
			emit_area_sum += objects[k]->getArea();
		}
	}
	float p = get_random_float() * emit_area_sum;
	emit_area_sum = 0;
	for (uint32_t k = 0; k < objects.size(); ++k) {
		if (objects[k]->hasEmit()) {
			emit_area_sum += objects[k]->getArea();
			if (p <= emit_area_sum) {
				objects[k]->Sample(pos, pdf);
				break;
			}
		}
	}
}

bool Scene::trace(
	const Ray& ray,
	const std::vector<Object*>& objects,
	float& tNear, uint32_t& index, Object** hitObject)
{
	*hitObject = nullptr;
	for (uint32_t k = 0; k < objects.size(); ++k) {
		float tNearK = kInfinity;
		uint32_t indexK;
		Vector2f uvK;
		if (objects[k]->intersect(ray, tNearK, indexK) && tNearK < tNear) {
			*hitObject = objects[k];
			tNear = tNearK;
			index = indexK;
		}
	}


	return (*hitObject != nullptr);
}

// Implementation of Path Tracing
Vector3f Scene::castRay(const Ray& ray, int depth) const
{
	// TO DO Implement Path Tracing Algorithm here
	Intersection direct_light_inter = intersect(ray);
	if (!direct_light_inter.happened)
	{
		return Vector3f(0, 0, 0);
	}
	else if (direct_light_inter.m->hasEmission())
	{
		return direct_light_inter.m->getEmission();
	}
	Intersection inter;
	float pdf_light;
	sampleLight(inter, pdf_light);
	Vector3f wo = (-ray.direction).normalized();
	Vector3f hitPoint = direct_light_inter.coords;
	Material* m = direct_light_inter.m;
	Vector3f N = direct_light_inter.normal.normalized();
	Vector3f reflect = inter.coords - hitPoint;
	Vector3f ws = reflect.normalized();
	inter.distance = reflect.norm();
	bool block = ((intersect(Ray(hitPoint, ws)).distance - inter.distance) < EPSILON);
	Vector3f l_dir(0, 0, 0);
	if (!block) 
	{
		l_dir = inter.emit * m->eval(wo, ws, N) * dotProduct(ws, N) * dotProduct(-ws, inter.normal) / dotProduct(reflect, reflect) / pdf_light;
	}
	Vector3f l_indir = Vector3f(0, 0, 0);
	if (get_random_float() < RussianRoulette)
	{
		auto wi = m->sample(wo, N).normalized();
		Ray newRay(hitPoint, wi);
		Intersection nolight_reflectInter = intersect(newRay);
		if (nolight_reflectInter.happened && nolight_reflectInter.m->hasEmission()) 
		{
			l_indir = castRay(newRay, depth + 1) * m->eval(wo, wi, N) * dotProduct(wi, N) / m->pdf(wo, wi, N) / RussianRoulette;
		}
	}
	Vector3f res = l_dir + l_indir;
	return l_dir + l_indir;
}