#include "GravityForceGenerator.h"

GravityForceGenerator::GravityForceGenerator(const Vector3& g):_gravity(g)
{
}

void GravityForceGenerator::updateForce(Particle* particle)
{
	if (fabs(particle->getInvMass()))return;

	particle->addForce(_gravity * particle->getMass());
}
