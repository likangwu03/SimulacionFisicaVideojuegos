#include "SpringForceGenerator.h"


SpringForceGenerator::SpringForceGenerator(double k, double resting_length, Particle* other):_k(k),_resting_length(resting_length),_other(other) {

}
void SpringForceGenerator::updateForce(Particle* particle, double t) {
	Vector3 relative_pos = _other->getPosition() - particle->getPosition();
	Vector3 force;

	float length = relative_pos.normalize();
	float delta_x = length - _resting_length;

	force = relative_pos * delta_x * _k;

	particle->addForce(force);

}