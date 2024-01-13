
#pragma once
#include "UniformParticleGenerator.h"

class FireworkGenerator : public UniformParticleGenerator
{
public:
	FireworkGenerator(ParticleSystem* system, int n_particles, Vector3 pos, Vector3 area, double frequency, Particle* p = nullptr);

	void generateParticles() override;
};
