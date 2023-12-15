#include "WindSolidForceGenerator.h"



WindSolidForceGenerator::WindSolidForceGenerator(double k1, Vector3 vel, Vector3 area, Vector3 pos) :SolidForceGenerator(),
_k1(k1), _vel(vel), _area(area), _pos(pos)
{

}

void WindSolidForceGenerator::updateForce(DynamicObject* obj, double t)
{
	if (!_active)return;

	if (!inArea(obj->getRigid()->getGlobalPose().p))return;

	if (fabs(obj->getRigid()->getInvMass()) < 1e-10) return;

	Vector3 diff_vel = _vel - obj->getRigid()->getLinearVelocity();

	Vector3 force = _k1 * diff_vel + _k2 * abs(diff_vel.magnitude()) * diff_vel;

	obj->getRigid()->addForce(force);
}

bool WindSolidForceGenerator::inArea(Vector3 pos) {
	return pos.x > _pos.x - _area.x && pos.x<_pos.x + _area.x && pos.z>_pos.z - _area.z && pos.z < _pos.z + _area.z && pos.y>_pos.y && pos.y < _pos.y + _area.y;
}