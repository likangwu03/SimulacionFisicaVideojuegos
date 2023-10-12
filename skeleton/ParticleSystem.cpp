#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(const Vector3& g):_gravity(g)
{

}

void ParticleSystem::update(double t)
{


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
