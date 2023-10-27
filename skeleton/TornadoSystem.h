#pragma once
#include "UniformParticleGenerator.h"
#include "TurnParticle.h"

class TornadoSystem : public UniformParticleGenerator
{
public:
	TornadoSystem(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p = nullptr, Vector3 g = SFV::GRAVITY);

	virtual std::list<Particle*> generateParticles();
};

