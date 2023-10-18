#include "ParticleSystem.h"
#include "Scene.h"
class ParticleSystem;
ParticleSystem::ParticleSystem(Scene* scene, const Vector3& g):System(scene),_gravity(g)
{
	Vector3 p_aux = Vector3(0);
	Vector3 v_aux = Vector3(0);
	ParticleGenerator* generator_aux=new GaussianParticleGenerator(this,3, p_aux, Vector3(0,30,0), 0.01);
	_particle_generators.push_back(generator_aux);
}

void ParticleSystem::update(double t)
{
	for (ParticleGenerator* p : _particle_generators) {
		p->update(t);
	}

	auto it = _particles.begin();
	while (it != _particles.end()) {
		if ((*it)->getTime() > (*it)->getDuration()) {
			(*it)->setAlive(false);
			it=_particles.erase(it);
		}
		else {
			++it;
		}
	}
}


void ParticleSystem::addParticles(std::list<Particle*>& lista) {
	for (auto p : lista) {
		_particles.push_back(p);
		_scene->addObject(p);
	}
}