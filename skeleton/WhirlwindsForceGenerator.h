#pragma once
#include "WindForceGenerator.h"
class WhirlwindsForceGenerator :public WindForceGenerator
{
public:
	WhirlwindsForceGenerator(double K,double Y, double k1, Vector3 vel, Vector3 area, Vector3 pos);
	void updateForce(Particle* particle,double t) override;
protected:
	double _K;
	double _Y;
};

