#include "ParticleSystem.h"
#include "Scene.h"

ParticleSystem::ParticleSystem(Scene* scene, const Vector3& g) :System(scene, SFV::SystemId::_sys_PARTICLE), _gravity(g),
particleForceRegistry()
{
	
}

void ParticleSystem::update(double t)
{
	for (ParticleGenerator* p : _particle_generators) {
		p->update(t);
	}

	for (auto fg : _forceGenerators) {
		if (fg->updateTime(t)) {
			fg->setActive(false);
		}
	}

	particleForceRegistry.updateForces(t);

	refresh();
}

void ParticleSystem::addForce(ForceGenerator* g)
{
	_forceGenerators.push_back(g);
	for (auto p : _particles) {
		particleForceRegistry.addRegistry(g, p);
	}
}

void ParticleSystem::removeForce(ForceGenerator* g)
{
	particleForceRegistry.deleteForcesRegistry(g);
	_forceGenerators.remove(g);
	delete g;
}



void ParticleSystem::refresh() {
	auto it = _particles.begin();
	while (it != _particles.end()) {
		if ((*it)->getTime() > (*it)->getDuration()) {
			(*it)->setAlive(false);

			particleForceRegistry.deletePArticleRegistry(*it);

			it = _particles.erase(it);
		}
		else {
			++it;
		}
	}

	auto it2 = _forceGenerators.begin();
	while (it2 != _forceGenerators.end()) {
		if (!(*it2)->isAlive()) {
			
			particleForceRegistry.deleteForcesRegistry(*it2);

			it2 = _forceGenerators.erase(it2);

			std::cout << "des\n";
		}
		else {
			++it2;
		}
	}


}
//template <typename Valor>
void ParticleSystem::addParticle(Particle* p)
{
	_particles.push_back(p);
	_scene->addObject(p);
	for (auto f : _forceGenerators) {
		particleForceRegistry.addRegistry(f, p);
	}
}
