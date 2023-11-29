#pragma once
#include "ForceGenerator.h"
#include "BoxParticle.h"
class BuoyancyForceGenerator :public ForceGenerator
{
public:
	BuoyancyForceGenerator(float h,float v,float d);
	virtual void updateForce(Particle* particle, double t);
	virtual ~BuoyancyForceGenerator();

	void setHeight(float h) { _height = h; }
	float getHeight() { return _height; }
	void setVolume(float v) { _volume = v; }
	float getVolume() { return _volume; }

	void setDensity(float d) { _liquid_density = d; }
	float getDensity() { return _liquid_density; }

protected:
	float _height;
	float _volume;
	float _liquid_density;
	float _gravity = 9.8;

	Particle* _liquid_particle;
};

