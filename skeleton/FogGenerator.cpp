#include "FogGenerator.h"
#include "ParticleSystem.h"


void FogGenerator::generateParticles()
{
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = _velocity + Vector3(uniform_distributions[0](gen), uniform_distributions[0](gen), uniform_distributions[0](gen));

		Particle* p = _model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		_system->addParticle(p);

	}
}
