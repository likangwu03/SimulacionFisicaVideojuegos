#pragma once
#include "ParticleSystem.h"
#include "ExplosionForceGenerator.h"
#include "GravityForceGenerator.h"
#include "WhirlwindsForceGenerator.h"
#include "WindForceGenerator.h"
class ParticleSystemP3 : public ParticleSystem
{
public:
	ParticleSystemP3(Scene* scene, const Vector3& g = SFV::GRAVITY);
	void update(double t) override;
	virtual void keyPress(unsigned char key);
	~ParticleSystemP3();
protected:
	std::vector<bool> activas;
	WhirlwindsForceGenerator* whirlwinds = nullptr;
	GravityForceGenerator* gravity = nullptr;
	WindForceGenerator* wind = nullptr;
	

	void createExplosion();
};

