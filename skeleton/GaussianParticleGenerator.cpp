#include "GaussianParticleGenerator.h"
#include "ParticleSystem.h"

GaussianParticleGenerator::GaussianParticleGenerator(ParticleSystem* system,int n_particle, Vector3 pos, Vector3 vel, double frequency , Particle* p,Vector3 g) 
	:ParticleGenerator(system,n_particle,pos,vel,frequency,g)
{
	if (_model_particle == nullptr) {
		_model_particle = new Particle(pos, vel, _gravity);
		_model_particle->removeRenderItem();
	}
	addNormalDistrinution(0, 15);
}

std::list<Particle*> GaussianParticleGenerator::generateParticles()
{
	std::list<Particle*> lista;
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = _velocity + Vector3(normal_distributions[0](gen), normal_distributions[0](gen), normal_distributions[0](gen));

		Particle* p = _model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		lista.push_back(p);
	}
	return lista;
}



void GaussianParticleGenerator::update(double t) {
	_cont += t;
	if (_cont > _frequency) {
		_cont = 0;
		std::list<Particle*> lista=generateParticles();
		_system->addParticles(lista);
	}
}

void GaussianParticleGenerator::addNormalDistrinution(float mean, float deviation)
{
	std::normal_distribution<float> aux(mean, deviation);

	normal_distributions.push_back(aux);

}

void GaussianParticleGenerator::setDeviationVel(float deviation)
{
	normal_distributions[0] = std::normal_distribution<float>(0, deviation);
}
