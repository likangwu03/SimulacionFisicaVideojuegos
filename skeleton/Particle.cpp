#include "Particle.h"

Particle::Particle(ParticleInfor info):Object(), _vel(info.Vel), _accel(info.accel), _duration(info.duration),
_damping(info.damping), _type(info.type),_inv_masa(1/info.masa), _cont(0), renderItem(nullptr) {
	_pos = physx::PxTransform(info.Pos);

	if (_type == ParticleType::_particle_default) {
		PxSphereGeometry a;
		a.radius = 1;
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, Vector4(0.1, 1, 1, 1));
		RegisterRenderItem(renderItem);
	}

}

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 accel,double masa, double duration,double damping, ParticleType type):Object(),
_vel(Vel),_accel(accel),_duration(duration),_damping(damping), _type(type), _inv_masa(1 / masa), _cont(0), renderItem(nullptr)
{
	_pos = physx::PxTransform(Pos);

	if (_type == ParticleType::_particle_default) {
		PxSphereGeometry a;
		a.radius = 1;
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

	if (_cont > _duration) {
		setAlive(false);
	}
}

Particle* Particle::clone()
{
	Particle* p = new Particle(_pos.p, _vel, _accel, 1 / _inv_masa, _duration, _damping, _type);
	return p;
}
