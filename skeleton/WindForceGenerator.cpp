#include "WindForceGenerator.h"
#include "checkML.h"
WindForceGenerator::WindForceGenerator(double k1, Vector3 vel, Vector3 area, Vector3 pos):ForceGenerator(),
	_k1(k1),_vel(vel),_area(area),_pos(pos)
{

}

void WindForceGenerator::updateForce(Particle* particle, double t)
{
	if (!_active)return;

	if (!inArea(particle->getPosition()))return;

	if (fabs(particle->getInvMass()) < 1e-10) return;

	Vector3 diff_vel = _vel - particle->getVelocity();

	Vector3 force = _k1 * diff_vel + _k2*abs(diff_vel.magnitude()) * diff_vel;

	particle->addForce(force);
}

bool WindForceGenerator::inArea(Vector3 pos) {
	return pos.x > _pos.x - _area.x && pos.x<_pos.x + _area.x && pos.z>_pos.z - _area.z && pos.z < _pos.z + _area.z && pos.y>_pos.y && pos.y < _pos.y + _area.y;
}