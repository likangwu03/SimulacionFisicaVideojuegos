#include "ParticleSystem.h"
#include "Scene.h"

ParticleSystem::ParticleSystem(Scene* scene, const Vector3& g) :System(scene, SFV::SystemId::_sys_PARTICLE), _gravity(g)
{
	
	
}

void ParticleSystem::update(double t)
{
	for (ParticleGenerator* p : _particle_generators) {
		p->update(t);
	}
	refresh();
}

template <typename Valor>
void ParticleSystem::addParticles(std::list<Valor*>& lista) {
	for (auto p : lista) {
		_particles.push_back(p);
		_scene->addObject(p);
	}

}

void ParticleSystem::refresh() {
	auto it = _particles.begin();
	while (it != _particles.end()) {
		if ((*it)->getTime() > (*it)->getDuration()) {
			(*it)->setAlive(false);
			it = _particles.erase(it);
		}
		else {
			++it;
		}
	}
}
//template <typename Valor>
void ParticleSystem::addParticle(Particle* p)
{
	_particles.push_back(p);
	_scene->addObject(p);
}
