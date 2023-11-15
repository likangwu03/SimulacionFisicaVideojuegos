#pragma once
#include "WindForceGenerator.h"
class WhirlwindsForceGenerator :public WindForceGenerator
{
public:
	WhirlwindsForceGenerator(double k1, double K , Vector3 origin , double duration);
	void updateForce(Particle* particle) override;
protected:
	Vector3 origin;
	double K;
};

