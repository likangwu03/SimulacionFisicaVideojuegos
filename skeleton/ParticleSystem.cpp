#include "ParticleSystem.h"
#include "Scene.h"

ParticleSystem::ParticleSystem(Scene* scene, const Vector3& g) :System(scene, SFV::SystemId::_sys_PARTICLE), _gravity(g)
{
	/*
	Vector3 p_aux = Vector3(0);
	ParticleGenerator* generator_aux = new CircleGenerator("cicle", this, 3, p_aux, Vector3(0, 5, 0), 0.01,nullptr,Vector3(0));
	_particle_generators.push_back(generator_aux);
	
	Vector3 p_aux2 = Vector3(50,0,0);
	ParticleGenerator* generator_aux2 = new Fountain("fountain", this, 3, p_aux2, Vector3(0, 10, 0), 0.01);
	_particle_generators.push_back(generator_aux2);
	*/

	Vector3 p_aux3 = Vector3(50, 0, 0);
	ParticleGenerator* generator_aux3 = new TornadoSystem("tornado", this, 3, p_aux3, Vector3(0, 10, 0), 0.1);
	_particle_generators.push_back(generator_aux3);
}

void ParticleSystem::update(double t)
{
	for (ParticleGenerator* p : _particle_generators) {
		p->update(t);
	}
}

