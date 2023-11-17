#include "ParticleGenerator.h"
#include "ParticleSystem.h"
#include "checkML.h"
ParticleGenerator::ParticleGenerator(ParticleSystem* system,int n_particles, Vector3 pos, Vector3 velocity, double frequency, Vector3 gravity, Particle* p) :
	_system(system),_n_particles(n_particles),
_origin(pos), _velocity(velocity), _frequency(frequency), _gravity(gravity),_cont(0), _model_particle(p)
{
	gen = std::mt19937(rd());
	_scene = system->getScene();
}

ParticleGenerator::~ParticleGenerator()
{
	delete _model_particle;
}
