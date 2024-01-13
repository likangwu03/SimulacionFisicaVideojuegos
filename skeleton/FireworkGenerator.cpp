#include "FireworkGenerator.h"
#include "ParticleSystem.h"


FireworkGenerator::FireworkGenerator( ParticleSystem* system, int n_particles, Vector3 pos, Vector3 area, double frequency, Particle* p) :UniformParticleGenerator(system, n_particles, pos, Vector3(0), frequency, p)
{
	addUniformDistribution(pos.x - area.x, pos.x + area.x);
	addUniformDistribution(pos.y - area.y, pos.y + area.y);
	addUniformDistribution(pos.z - area.z, pos.z + area.z);
}

void FireworkGenerator::generateParticles()
{
	for (int i = 0; i < _n_particles; ++i) {
		Particle* p = _model_particle->clone();
		p->setPos(Vector3(uniform_distributions[1](gen), uniform_distributions[2](gen), uniform_distributions[3](gen)));
		_system->addParticle(p,false);

	}
}
