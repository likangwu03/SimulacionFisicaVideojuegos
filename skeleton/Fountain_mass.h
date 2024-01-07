#pragma once
#include "Fountain.h"

class Fountain_mass : public Fountain
{
public:
	Fountain_mass(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p = nullptr);

	void generateParticles() override;
};

