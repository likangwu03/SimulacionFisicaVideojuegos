#include "GravityForceGenerator.h"

GravityForceGenerator::GravityForceGenerator(const Vector3& g):_gravity(g)
{
}

void GravityForceGenerator::updateForce(Particle* particle)
{
	if (fabs(particle->getInvMass()) < 1e-10) return;

	particle->addForce(_gravity * particle->getMass());
}
