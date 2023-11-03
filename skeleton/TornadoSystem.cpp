#include "TornadoSystem.h"
#include "ParticleSystem.h"
#include "Scene.h"

TornadoSystem::TornadoSystem(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Particle* p, Vector3 g) :UniformParticleGenerator(system, n_particles, pos, vel, frequency, p, g)
{
	addUniformDistribution(0, 360);
	//setUniformDistribution(0, 2 * SFV::M_PI);
}

void TornadoSystem::generateParticles()
{
	for (int i = 0; i < _n_particles; ++i) {

		Particle::ParticleInfor infor;
		infor.Vel = Vector3(0, 10, 2);
		infor.duration = 15;
		infor.accel = Vector3(0);
		infor.Pos = _origin;
		int grado = uniform_distributions[1](gen);
		TurnParticle* f = new TurnParticle(0, grado, 180, infor);
		_system->addParticle(f);
	}
}

