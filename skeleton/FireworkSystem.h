#pragma once
#include "GaussianParticleGenerator.h"

class FireworkSystem : public GaussianParticleGenerator
{
public:
	FireworkSystem(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p = nullptr, Vector3 g = SFV::GRAVITY);


	virtual void generate();
};


