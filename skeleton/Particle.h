#pragma once
#include <PxPhysics.h>
using namespace physx;

#include "core.hpp"
#include "RenderUtils.hpp"
class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel,Vector3 ace=Vector3());
	~Particle();

	virtual void integrate(double t);
protected:
	Vector3 vel;
	Vector3 a;
	PxTransform pos;
	RenderItem* renderItem;

	const double damping = 0.998;
};

