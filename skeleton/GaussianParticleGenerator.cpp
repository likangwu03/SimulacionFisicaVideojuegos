#include "GaussianParticleGenerator.h"
#include "ParticleSystem.h"

GaussianParticleGenerator::GaussianParticleGenerator(ParticleSystem* system,int n_particle, Vector3 pos, Vector3 vel, double frequency , Particle* p,Vector3 g) 
	:ParticleGenerator(system,n_particle,pos,vel,frequency,g)
{
	/*if (_model_particle == nullptr) {
		_model_particle = new Particle(pos, vel, _gravity);
		_model_particle->removeRenderItem();
	}*/
	gen = std::mt19937(rd());
	d = std::normal_distribution<>(0, 5);
}

std::list<Particle*> GaussianParticleGenerator::generateParticles()
{
	std::list<Particle*> lista;
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = Vector3(d(gen),30, d(gen));

		Particle* p = new Particle(_origin, v_aux,_gravity);


		lista.push_back(p);
	}
	return lista;
}

void GaussianParticleGenerator::ini_rnd()
{

}


void GaussianParticleGenerator::update(double t) {
	_cont += t;
	if (_cont > _frequency) {
		_cont = 0;
		std::list<Particle*> lista=generateParticles();
		_system->addParticles(lista);
	}
}