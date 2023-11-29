#pragma once
#include "SpringForceGenerator.h"
class ElasticWireFG :public SpringForceGenerator
{
public:
	ElasticWireFG(double k, double resting_length, Particle* other);
	virtual void updateForce(Particle* particle, double t);
};

