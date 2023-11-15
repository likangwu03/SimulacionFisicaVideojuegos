#pragma once
#include "ForceGenerator.h"
class ExplosionForceGenerator :public ForceGenerator
{
public:
	ExplosionForceGenerator(Vector3 pos, double radius, double K, double duration);
	void updateForce(Particle* particle,double t) override;
private:

};

