#include "FireworkSystem.h"
#include "ParticleSystem.h"
FireworkSystem::FireworkSystem(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p, Vector3 g) :GaussianParticleGenerator(system, n_particles, pos, vel, frequency, p, g)
{
	//setDeviationVel(10);
}

void FireworkSystem::generate()
{
	auto l = generateParticles();
	_system->addParticles(l);
	
}

