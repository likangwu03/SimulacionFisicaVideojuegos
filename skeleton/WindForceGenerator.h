#pragma once
#include "ForceGenerator.h"
class WindForceGenerator :public ForceGenerator
{
public:
	WindForceGenerator(double k1 , Vector3 vel, Vector3 area,Vector3 pos);
	virtual void updateForce(Particle* particle, double t);
protected:
	double _k1;
	double _k2=0;
	Vector3 _vel; 
	Vector3 _area;
	Vector3 _pos;
};

