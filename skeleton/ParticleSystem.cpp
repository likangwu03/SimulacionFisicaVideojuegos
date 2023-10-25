#include "ParticleSystem.h"
#include "Scene.h"
class ParticleSystem;
ParticleSystem::ParticleSystem(Scene* scene, const Vector3& g) :System(scene, SFV::SystemId::_sys_PARTICLE), _gravity(g)
{
	/*Vector3 p_aux = Vector3(0);
	Vector3 v_aux = Vector3(0);
	ParticleGenerator* generator_aux = new CircleGenerator("fountain", this, 3, p_aux, Vector3(0, 5, 0), 0.01);
	_particle_generators.push_back(generator_aux);*/
}

void ParticleSystem::update(double t)
{
	for (ParticleGenerator* p : _particle_generators) {
		p->update(t);
	}
}

