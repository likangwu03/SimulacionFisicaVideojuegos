#pragma once
#include "ForceGenerator.h"
class ExplosionForceGenerator :public ForceGenerator
{
public:
	ExplosionForceGenerator(Vector3 origin, double radius, double K, double duration);
	void updateForce(Particle* particle) override;
private:

};

