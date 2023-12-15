#pragma once
#include "SolidForceGenerator.h"
class WindSolidForceGenerator :public SolidForceGenerator
{
public:
	WindSolidForceGenerator(double k1, Vector3 vel, Vector3 area, Vector3 pos);
	virtual void updateForce(DynamicObject* obj, double t);
protected:
	double _k1;
	double _k2 = 0;
	Vector3 _vel;
	Vector3 _area;
	Vector3 _pos;

	bool inArea(Vector3 pos);
};

