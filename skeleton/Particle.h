#pragma once
#include <PxPhysics.h>
#include "core.hpp"
#include "RenderUtils.hpp"

#include "Object.h"

using namespace physx;
class Particle:public Object
{
public:
	Particle(Vector3 Pos, Vector3 Vel,Vector3 ace=Vector3(),double damping= 0.998);
	~Particle();

	void integrate(double t) override;

protected:
	Vector3 vel;
	Vector3 a;
	PxTransform pos;
	RenderItem* renderItem;

	double damping_;
};

