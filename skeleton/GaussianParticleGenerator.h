#pragma once
#include "ParticleGenerator.h"

class GaussianParticleGenerator : public ParticleGenerator
{
public:
	GaussianParticleGenerator(ParticleSystem* system, int n_particle, Vector3 pos, Vector3 vel, double frequency,  Particle* p = nullptr, Vector3 g=SFV::GRAVITY);

	virtual std::list<Particle*> generateParticles();

	void update(double t) override;

private:
	void ini_rnd();
};

