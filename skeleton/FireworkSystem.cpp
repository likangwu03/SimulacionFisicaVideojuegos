#include "FireworkSystem.h"
#include "ParticleSystem.h"
#include "Scene.h"
#include "checkML.h"
FireworkSystem::FireworkSystem(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Fireword* p) :GaussianParticleGenerator(system, n_particles, pos, vel, frequency, p)
{
	//setModel(nullptr);
	//setModel(p);
	fireword = p;
	setDeviationVel(50);
	angulo = std::uniform_real_distribution<float>(0, 2 * SFV::M_PI);
	addNormalDistribution(-20, 5);

	addNormalDistribution(10, 2);
	addNormalDistribution(20, 2);
}




void FireworkSystem::generateParticles1()
{
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = _velocity + Vector3(normal_distributions[0](gen), normal_distributions[0](gen), normal_distributions[0](gen));
		
		Fireword* p = (Fireword*)_model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		_system->addParticle2(p);
		//_scene->addObject(p);
	}
}

void FireworkSystem::generateParticles2()
{
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = _velocity + Vector3(normal_distributions[0](gen), normal_distributions[0](gen), 0);

		Fireword* p = (Fireword*)_model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		_system->addParticle2(p);
	}
}

void FireworkSystem::generateParticles3()
{

	for (int i = 0; i < _n_particles; ++i) {
		float d = angulo(gen);
		float a = normal_distributions[2](gen);
		Vector3 v_aux = _velocity + Vector3(a * sinf(d), a * cosf(d), 0);

		Fireword* p = (Fireword*)_model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		_system->addParticle2(p);
	}
	for (int i = 0; i < _n_particles; ++i) {
		float d = angulo(gen);
		float a = normal_distributions[3](gen);
		Vector3 v_aux = _velocity + Vector3(a * sinf(d), a * cosf(d), 0);

		Fireword* p = (Fireword*)_model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		_system->addParticle2(p);
	}
}

void FireworkSystem::generateParticles4()
{
	for (int i = 0; i < _n_particles; ++i) {
		float d = angulo(gen);
		Vector3 v_aux = _velocity + Vector3(10 * sinf(d), 10 * cosf(d), 0);

		Fireword* p = (Fireword*)_model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		_system->addParticle2(p);
	}
	
	for (int i = 0; i < _n_particles; ++i) {
		float d = angulo(gen);
		Vector3 v_aux = _velocity + Vector3(20 * sinf(d), 20 * cosf(d), 0);

		Fireword* p = (Fireword*)_model_particle->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		_system->addParticle2(p);
	}
}
