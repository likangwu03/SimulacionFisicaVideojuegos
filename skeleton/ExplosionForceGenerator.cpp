#include "ExplosionForceGenerator.h"


ExplosionForceGenerator::ExplosionForceGenerator(Vector3 pos, double radius, double K, double duration):ForceGenerator(duration),
	_pos(pos),_K(K), _maxRadius(radius)
{
	std::cout << "create\n";
}

void ExplosionForceGenerator::updateForce(Particle* particle,double t)
{
	if (!_active)return;
	if (fabs(particle->getInvMass()) < 1e-10) return;

	Vector3 diff_pos = particle->getPosition() - _pos;

	double r = diff_pos.magnitude();

	_radius = (_maxRadius / _duration) * _t;
	if (r > _radius)return;
	if (r < 1e-10) r = 0.01;

	Vector3 force = (_K / (_radius * _radius)) * diff_pos * exp(-_t / _duration);

	particle->addForce(force);
}
