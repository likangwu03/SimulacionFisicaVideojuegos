#include "LineGenerator.h"
#include "ParticleSystem.h"
#include "Scene.h"
LineGenerator::LineGenerator(ParticleSystem* system, int n_particle, Vector3 pos, Vector3 vel, double frequency, Particle* p)
	:ParticleGenerator(system, n_particle, pos, vel, frequency, p),d(5)
{
	if (_model_particle == nullptr) {
		_model_particle = new Particle(pos, vel);
		_model_particle->removeRenderItem();
	}
}

void LineGenerator::generateParticles()
{
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = _velocity;
		Particle* p = _model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		p->setDuration(d);
		_system->addParticle(p);
	}
}

void LineGenerator::update(double t)
{
	if (!active)return;
	_cont += t;
	if (_cont > _frequency) {
		_cont = 0;
		generateParticles();
	}
}
