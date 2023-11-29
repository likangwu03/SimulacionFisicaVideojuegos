#include "ParticleDragGenerator.h"

ParticleDragGenerator::ParticleDragGenerator():ForceGenerator()
{
}

void ParticleDragGenerator::updateForce(Particle* particle, double t)
{
	if (!_active)return;
	if (fabs(particle->getInvMass()) < 1e-10) return;

	Vector3 v = particle->getVelocity();
	
	float drag_coef = v.normalize();
	
	drag_coef = _k1 * drag_coef + _k2 * drag_coef * drag_coef;
	Vector3 dragF=-v* drag_coef;
	particle->addForce(dragF);
}
