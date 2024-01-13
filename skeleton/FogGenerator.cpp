#include "FogGenerator.h"
#include "ParticleSystem.h"


FogGenerator::FogGenerator(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 area, float speed, double frequency, Particle* p):UniformParticleGenerator(system, n_particles, pos, Vector3(0), frequency, p)
{
	addUniformDistribution(0, speed);
	addUniformDistribution(pos.x- area.x, pos.x + area.x);
	addUniformDistribution(pos.y - area.y, pos.y + area.y);
	addUniformDistribution(pos.z - area.z, pos.z + area.z);
}

void FogGenerator::generateParticles()
{
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = Vector3(uniform_distributions[1](gen), uniform_distributions[1](gen), uniform_distributions[1](gen));

		Particle* p = _model_particle->clone();
		p->setPos(Vector3(uniform_distributions[2](gen), uniform_distributions[3](gen), uniform_distributions[4](gen)));
		p->setVel(v_aux);
		_system->addParticle(p);

	}
}
