#include "Fountain.h"
#include "Scene.h"
/*
Fountain::Fountain(std::string name, Vector3 pos,  Vector3 vel, Vector3 g, Particle* p):ParticleGenerator()
{
	_name = name;
	_origin = pos;
	_velocity = vel;
	_model_particle = p;
	_gravity = g;
	if (_model_particle == nullptr) {
		_model_particle=new Particle(pos, vel, _gravity);
		_model_particle->removeRenderItem();
	}
}
*/
Fountain::Fountain(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p, Vector3 g):GaussianParticleGenerator(system,n_particles,pos,vel,frequency,p,g)
{
	addNormalDistribution(7, 3);
	setDeviationVel(10);
}

std::list<Particle*> Fountain::generateParticles()
{
	std::list<Particle*> lista;
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = _velocity + Vector3(normal_distributions[0](gen), normal_distributions[1](gen), normal_distributions[0](gen));

		Particle* p = _model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);

		_scene->addObject(p);

		lista.push_back(p);
	}
	return lista;
}

