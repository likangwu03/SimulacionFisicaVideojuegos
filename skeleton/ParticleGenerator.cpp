#include "ParticleGenerator.h"
#include "ParticleSystem.h"
ParticleGenerator::ParticleGenerator(ParticleSystem* system,int n_particles, Vector3 pos, Vector3 velocity, double frequency, Vector3 gravity) : 
	_system(system),_n_particles(n_particles),
_origin(pos), _velocity(velocity), _frequency(frequency), _gravity(gravity),_cont(0)
{
	gen = std::mt19937(rd());
}

ParticleGenerator::~ParticleGenerator()
{
	delete _model_particle;
}
