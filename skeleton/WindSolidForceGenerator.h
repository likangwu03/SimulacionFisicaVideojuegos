#pragma once
#include "SolidForceGenerator.h"
#include <cmath>
class WindSolidForceGenerator :public SolidForceGenerator
{
public:
	WindSolidForceGenerator(double k1, Vector3 vel, Vector3 area, Vector3 pos);
	virtual void updateForce(DynamicObject* obj, double t);

	const float densidad = 1.2250;
	const float Cd = 0.5;
protected:
	double _k1;
	double _k2 = 0;
	Vector3 _vel;
	Vector3 _area;
	Vector3 _pos;

	bool inArea(Vector3 pos);
};

