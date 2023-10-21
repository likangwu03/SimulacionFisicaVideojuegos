#include "FireworkSystem.h"
#include "ParticleSystem.h"
FireworkSystem::FireworkSystem(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Fireword* p, Vector3 g) :GaussianParticleGenerator(system, n_particles, pos, vel, frequency, p, g)
{
	fireword = p;
	//setDeviationVel(10);
}

void FireworkSystem::generate()
{
	auto l = generateParticles();
	_system->addParticles(l);
	
}


std::list<Particle*> FireworkSystem::generateParticles()
{
	std::list<Particle*> lista;
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = _velocity + Vector3(normal_distributions[0](gen), normal_distributions[0](gen), normal_distributions[0](gen));
		
		Particle* p = (Fireword*)fireword->clone();
		p->setPos(_origin);
		p->setVel(v_aux);
		lista.push_back(p);
	}
	return lista;
}
