#pragma once
#include "GaussianParticleGenerator.h"

class Fountain: public GaussianParticleGenerator
{
public:
	Fountain(std::string name,ParticleSystem* system,int n_particles, Vector3 pos,  Vector3 vel, double frequency, Particle* p=nullptr);

	void generateParticles() override;
};

