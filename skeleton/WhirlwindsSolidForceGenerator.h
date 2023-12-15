#pragma once
#include "WindSolidForceGenerator.h"
class WhirlwindsSolidForceGenerator :public WindSolidForceGenerator
{
public:
	WhirlwindsSolidForceGenerator(double K, double Y, double k1, Vector3 vel, Vector3 area, Vector3 pos);
	void updateForce(DynamicObject* obj, double t) override;
protected:
	double _K;
	double _Y;
};

