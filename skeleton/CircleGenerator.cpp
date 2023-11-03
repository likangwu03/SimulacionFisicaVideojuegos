#include "CircleGenerator.h"
#include "Scene.h"
#include "ParticleSystem.h"

CircleGenerator::CircleGenerator(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p, Vector3 g) :GaussianParticleGenerator(system, n_particles, pos, vel, frequency, p, g)
{
	addNormalDistribution(7, 3);
	setDeviationVel(10);
	angulo = std::uniform_real_distribution<float>(0, 2*SFV::M_PI);
}

void CircleGenerator::generateParticles()
{
	for (int i = 0; i < _n_particles; ++i) {
		float d = angulo(gen);
		Vector3 v_aux = _velocity + Vector3(normal_distributions[0](gen)*sinf(d), normal_distributions[1](gen)*cosf(d), 0);

		Particle* p = _model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		_system->addParticle(p);
		
	}
	
}

