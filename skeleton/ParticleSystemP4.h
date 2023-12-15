
#pragma once
#include "ParticleSystem.h"
#include "ExplosionForceGenerator.h"
#include "GravityForceGenerator.h"
#include "WhirlwindsForceGenerator.h"
#include "WindForceGenerator.h"
#include "Fountain_mass.h"
#include "BuoyancyForceGenerator.h"
#include "ParticleDragGenerator.h"

#include "AnchoredSpringFG.h"
#include "ElasticWireFG.h"

#include "BoxParticle.h"



class ParticleSystemP4 : public ParticleSystem
{
public:
	ParticleSystemP4(Scene* scene, const Vector3& g = SFV::GRAVITY);
	
	~ParticleSystemP4(){};

	virtual void keyPress(unsigned char key);
	void createExplosion();
private:
	const double k = 200;
	const float d = 5;
protected:
	std::vector<bool> activas;
	WhirlwindsForceGenerator* whirlwinds = nullptr;
	GravityForceGenerator* gravity = nullptr;
	WindForceGenerator* wind = nullptr;
	ParticleDragGenerator* drag = nullptr;
	ParticleDragGenerator* drag2 = nullptr;
	AnchoredSpringFG* f3 = nullptr;

	BuoyancyForceGenerator* Buoyancy = nullptr;
	BoxParticle* p = nullptr;


	void MuelleDemo();

	void comaElastica();

	void bateria(int n);

	void flotacion();
};

