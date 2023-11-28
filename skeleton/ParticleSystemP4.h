
#pragma once
#include "ParticleSystem.h"
#include "ExplosionForceGenerator.h"
#include "GravityForceGenerator.h"
#include "WhirlwindsForceGenerator.h"
#include "WindForceGenerator.h"
#include "Fountain_mass.h"

#include "AnchoredSpringFG.h"



class ParticleSystemP4 : public ParticleSystem
{
public:
	ParticleSystemP4(Scene* scene, const Vector3& g = SFV::GRAVITY);
	
	~ParticleSystemP4(){};
protected:
	std::vector<bool> activas;
	WhirlwindsForceGenerator* whirlwinds = nullptr;
	GravityForceGenerator* gravity = nullptr;
	WindForceGenerator* wind = nullptr;


	void MuelleDemo();
};

