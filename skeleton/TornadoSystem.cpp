#include "TornadoSystem.h"

#include "Scene.h"

TornadoSystem::TornadoSystem(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p, Vector3 g) :UniformParticleGenerator(system, n_particles, pos, vel, frequency, p, g)
{
	addUniformDistribution(0, 360);
	//setUniformDistribution(0, 2 * SFV::M_PI);
}

std::list<Particle*> TornadoSystem::generateParticles()
{
	std::list<Particle*> lista;
	for (int i = 0; i < _n_particles; ++i) {

		Particle::ParticleInfor infor;
		infor.Vel = Vector3(0, 10, 2);
		infor.duration = 15;
		infor.accel = Vector3(0);
		infor.Pos = _origin;
		int grado = uniform_distributions[1](gen);
		TurnParticle* f = new TurnParticle(0, grado, 180, infor);
		

		_scene->addObject(f);

		lista.push_back(f);
	}
	return lista;
}

