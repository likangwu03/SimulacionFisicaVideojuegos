#pragma once
#include "ForceGenerator.h"
class WindForceGenerator :public ForceGenerator
{
public:
	WindForceGenerator(double k1 , Vector3 windVel, double duration, Vector3 area);
	virtual void updateForce(Particle* particle);

};

