#include "WhirlwindsForceGenerator.h"

WhirlwindsForceGenerator::WhirlwindsForceGenerator(double K, double Y, double k1, Vector3 vel, Vector3 area, Vector3 pos) :
	WindForceGenerator(k1, vel, area, pos), _K(K), _Y(Y)
{

}

void WhirlwindsForceGenerator::updateForce(Particle* particle,double t)
{
	if (!_active)return;
	if (!inArea(particle->getPosition())) return;
	if (fabs(particle->getInvMass()) < 1e-10) return;

	Vector3 particle_pos = particle->getPosition();

	//_vel =_K*Vector3(-(particle_pos.z - _pos.z), _Y - (particle_pos.y - _pos.y), particle_pos.x - _pos.x);
	_vel =_K*Vector3(-(particle_pos.z - _pos.z), _Y , particle_pos.x - _pos.x);

	WindForceGenerator::updateForce(particle, t);

}


