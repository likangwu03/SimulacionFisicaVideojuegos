
#pragma once
#include "ParticleGenerator.h"

class UniformParticleGenerator : public ParticleGenerator
{
public:
	UniformParticleGenerator(ParticleSystem* system, int n_particle, Vector3 pos, Vector3 vel, double frequency, Particle* p = nullptr, Vector3 g = SFV::GRAVITY);

	virtual std::list<Particle*> generateParticles();

	void update(double t) override;

protected:
	std::vector< std::uniform_real_distribution<float>> uniform_distributions;

	void addUniformDistribution(float ini, float fin);

	void setUniformDistribution(float ini, float fin);

};

