#pragma once
#include "GaussianParticleGenerator.h"
#include <cmath>

class CircleGenerator : public GaussianParticleGenerator
{
public:
	CircleGenerator(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p = nullptr, Vector3 g = SFV::GRAVITY);

	void generateParticles() override;
protected:
	std::uniform_real_distribution<float> angulo;
};

