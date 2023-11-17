#include "Fountain_mass.h"
#include "Scene.h"
#include "ParticleSystem.h"
#include "checkML.h"
Fountain_mass::Fountain_mass(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p, Vector3 g) :
	Fountain(name,system,n_particles,pos,vel,frequency,p,g)
{
	addNormalDistribution(50, 49);
}

void Fountain_mass::generateParticles()
{
	for (int i = 0; i < _n_particles; ++i) {
		Vector3 v_aux = _velocity + Vector3(normal_distributions[0](gen), normal_distributions[1](gen), normal_distributions[0](gen));
		Particle::ParticleInfor infor;
		infor.masa = normal_distributions[2](gen);
		infor.type = _particle_mass;
		Particle* p = new Particle(infor);
		p->setPos(_origin);
		p->setVel(v_aux);
		
		_system->addParticle(p);
	}
}

