#include "Fountain.h"
#include "Scene.h"
#include "ParticleSystem.h"
Fountain::Fountain(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p, Vector3 g):GaussianParticleGenerator(system,n_particles,pos,vel,frequency,p,g)
{
	addNormalDistribution(20, 3);
	setDeviationVel(5);
}

void Fountain::generateParticles()
{
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = _velocity + Vector3(normal_distributions[0](gen), normal_distributions[1](gen), normal_distributions[0](gen));
		Particle* p = _model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		_system->addParticle(p);
	}
}

