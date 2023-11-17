#include "GravityForceGenerator.h"
#include "checkML.h"
GravityForceGenerator::GravityForceGenerator(const Vector3& g):_gravity(g)
{
}

void GravityForceGenerator::updateForce(Particle* particle, double t)
{
	if (!_active)return;
	if (fabs(particle->getInvMass()) < 1e-10) return;

	particle->addForce(_gravity * particle->getMass());
}
