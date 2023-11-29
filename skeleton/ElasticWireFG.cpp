#include "ElasticWireFG.h"

ElasticWireFG::ElasticWireFG(double k, double resting_length, Particle* other):SpringForceGenerator(k, resting_length, other)
{

}

void ElasticWireFG::updateForce(Particle* particle, double t)
{
	Vector3 relative_pos = _other->getPosition() - particle->getPosition();
	Vector3 force;

	float length = relative_pos.normalize();

	if (length < _resting_length) return;
	float delta_x = length - _resting_length;


	force = relative_pos * delta_x * _k;

	particle->addForce(force);
}
