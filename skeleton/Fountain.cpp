#include "Fountain.h"

Fountain::Fountain(std::string name, Vector3 pos,  Vector3 vel, Vector3 g, Particle* p):ParticleGenerator()
{
	_name = name;
	_origin = pos;
	_mean_velocity = vel;
	_model_particle = p;
	_gravity = g;
	if (_model_particle == nullptr) {
		_model_particle=new Particle(pos, vel, _gravity);
		_model_particle->removeRenderItem();
	}
}

std::list<Particle*> Fountain::generateParticles()
{
	std::list<Particle*> lista;
	for (int i = 0; i < _n_particles; ++i) {
		Particle* p = _model_particle->clone();

	}

	return lista;
}

void Fountain::ini_rnd()
{
	gen= std::mt19937(rd());
	d= std::normal_distribution<>(5, 2);
}
