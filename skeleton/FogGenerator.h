
#pragma once
#include "UniformParticleGenerator.h"

class FogGenerator : public UniformParticleGenerator
{
public:
	FogGenerator(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 area, float speed, double frequency, Particle* p = nullptr);

	void generateParticles() override;
};


