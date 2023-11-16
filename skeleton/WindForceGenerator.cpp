#include "WindForceGenerator.h"
WindForceGenerator::WindForceGenerator(double k1, Vector3 vel, Vector3 area, Vector3 pos):ForceGenerator(),
	_k1(k1),_vel(vel),_area(area),_pos(pos)
{

}

void WindForceGenerator::updateForce(Particle* particle, double t)
{
	if (!_active)return;
	if (fabs(particle->getInvMass()) < 1e-10) return;

	Vector3 diff_vel = _vel - particle->getVelocity();

	Vector3 force = _k1 * diff_vel + _k2*abs(diff_vel.magnitude()) * diff_vel;

	particle->addForce(force);
}
