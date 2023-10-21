#pragma once
#include "GaussianParticleGenerator.h"
#include "Fireword.h"
class FireworkSystem : public GaussianParticleGenerator
{
public:
	FireworkSystem(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Fireword* p = nullptr, Vector3 g = SFV::GRAVITY);


	virtual void generate();
	std::list<Particle*> generateParticles() override;
protected:
	Fireword* fireword;
};


