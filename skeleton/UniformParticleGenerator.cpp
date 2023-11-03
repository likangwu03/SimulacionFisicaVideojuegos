#include "UniformParticleGenerator.h"
#include "ParticleSystem.h"
#include "Scene.h"
UniformParticleGenerator::UniformParticleGenerator(ParticleSystem* system, int n_particle, Vector3 pos, Vector3 vel, double frequency, Particle* p, Vector3 g)
	:ParticleGenerator(system, n_particle, pos, vel, frequency, g)
{
	if (_model_particle == nullptr) {
		_model_particle = new Particle(pos, vel, _gravity);
		_model_particle->removeRenderItem();
	}
	addUniformDistribution(0, 15);
}

void UniformParticleGenerator::generateParticles()
{
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = _velocity + Vector3(uniform_distributions[0](gen), uniform_distributions[0](gen), uniform_distributions[0](gen));

		Particle* p = _model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		_system->addParticle(p);
	
	}
}



void UniformParticleGenerator::update(double t) {
	_cont += t;
	if (_cont > _frequency) {
		_cont = 0;
		generateParticles();
	}
}

void UniformParticleGenerator::addUniformDistribution(float ini, float fin)
{
	std::uniform_real_distribution<float> aux(ini, fin);

	uniform_distributions.push_back(aux);

}

void UniformParticleGenerator::setUniformDistribution(float ini, float fin)
{
	uniform_distributions[0] = std::uniform_real_distribution<float>(ini, fin);
}

