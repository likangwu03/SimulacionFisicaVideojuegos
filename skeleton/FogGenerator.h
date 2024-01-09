
#pragma once
#include "UniformParticleGenerator.h"
#include "TurnParticle.h"

class FogGenerator : public UniformParticleGenerator
{
public:
	FogGenerator(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p = nullptr);

	void generateParticles() override;
};


