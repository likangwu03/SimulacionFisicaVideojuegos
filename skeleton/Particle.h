#pragma once
#include <PxPhysics.h>
using namespace physx;

#include "core.hpp"
#include "RenderUtils.hpp"
class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel);
	~Particle();

	void integrate(double t);
private:
	Vector3 vel;
	PxTransform pos;
	RenderItem* renderItem;
};

