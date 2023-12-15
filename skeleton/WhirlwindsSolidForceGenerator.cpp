#include "WhirlwindsSolidForceGenerator.h"


WhirlwindsSolidForceGenerator::WhirlwindsSolidForceGenerator(double K, double Y, double k1, Vector3 vel, Vector3 area, Vector3 pos) :
	WindSolidForceGenerator(k1, vel, area, pos), _K(K), _Y(Y)
{

}

void WhirlwindsSolidForceGenerator::updateForce(DynamicObject* obj, double t)
{
	if (!_active)return;
	if (!obj->isAlive())return;
	if (!inArea(obj->getRigid()->getGlobalPose().p))return;

	if (fabs(obj->getRigid()->getInvMass()) < 1e-10) return;

	Vector3 particle_pos = obj->getRigid()->getGlobalPose().p;

	//_vel =_K*Vector3(-(particle_pos.z - _pos.z), _Y - (particle_pos.y - _pos.y), particle_pos.x - _pos.x);
	_vel = _K * Vector3(-(particle_pos.z - _pos.z), _Y, particle_pos.x - _pos.x);

	WindSolidForceGenerator::updateForce(obj, t);

}

