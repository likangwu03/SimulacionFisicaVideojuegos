#include "Particle.h"


Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 accel, double duration,double damping, ParticleType type):Object(),
_vel(Vel),_accel(accel),_duration(duration),_damping(damping), _type(type),_cont(0), renderItem(nullptr)
{
	_pos = physx::PxTransform(Pos);

	if (type == ParticleType::_particle_default) {
		PxSphereGeometry a;
		a.radius = 5;
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, Vector4(0.1, 1, 1, 1));
		RegisterRenderItem(renderItem);
	}

}

Particle::~Particle()
{
	if (renderItem != nullptr) {
		DeregisterRenderItem(renderItem);
		renderItem->release();
	}
}

void Particle::integrate(double t)
{
	_cont += t;

	_vel += _accel * t;

	// Impose drag (damping)
	_vel *= powf(_damping, t);

	// Update position
	_pos.p += _vel*t;
}

Particle* Particle::clone()
{
	Particle* p = new Particle(_pos.p, _vel, _accel, _duration, _damping, _type);
	return p;
}
