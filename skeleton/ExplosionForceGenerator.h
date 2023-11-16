#pragma once
#include "ForceGenerator.h"
class ExplosionForceGenerator :public ForceGenerator
{
public:
	ExplosionForceGenerator(Vector3 pos, double radius, double K, double duration);
	virtual void updateForce(Particle* particle, double t) ;
protected:
	double _K;
	double _radius;
	double _maxRadius;
	Vector3 _pos;
};

