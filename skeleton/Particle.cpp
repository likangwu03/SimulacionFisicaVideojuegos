#include "Particle.h"

Particle::Particle(ParticleInfor info):Object(), _vel(info.Vel), _accel(info.accel), _duration(info.duration),
_damping(info.damping), _type(info.type), _cont(0), renderItem(nullptr), _force(Vector3(0)) {
	_mass = info.masa;
	if (info.masa == 0)_inv_mass = 0;
	else _inv_mass = (1 / info.masa);

	_pos = physx::PxTransform(info.Pos);

	if (_type == ParticleType::_particle_default) {
		PxSphereGeometry a;
		a.radius = 1;
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, Vector4(0.1, 1, 1, 1));
		//RegisterRenderItem(renderItem);
	}
	else if (_type == ParticleType::_particle_F1) {
		PxSphereGeometry a;
		a.radius = 0.5;
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, Vector4(0.5, 0.8, 0, 1));
		//RegisterRenderItem(renderItem);
	}
	else if (_type == ParticleType::_particle_F2) {
		PxSphereGeometry a;
		a.radius = 0.3;
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, Vector4(0.9, 0.1, 0.1, 1));
		//RegisterRenderItem(renderItem);
	}

}

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 accel,double masa, double duration,double damping, ParticleType type):Object(),
_vel(Vel),_accel(accel),_duration(duration),_damping(damping), _type(type),_mass(masa), _inv_mass(1 / masa), _cont(0), renderItem(nullptr), _force(Vector3(0))
{
	_pos = physx::PxTransform(Pos);

	if (_type == ParticleType::_particle_default) {
		PxSphereGeometry a;
		a.radius = 1;
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, Vector4(0.1, 1, 1, 1));
		//RegisterRenderItem(renderItem);
	}
	else if (_type == ParticleType::_particle_F1) {
		PxSphereGeometry a;
		a.radius = 0.5;
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, Vector4(1, 0.8, 0, 1));
		//RegisterRenderItem(renderItem);
	}
	else if (_type == ParticleType::_particle_F2) {
		PxSphereGeometry a;
		a.radius = 0.3;
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, Vector4(0.8, 0, 0, 1));
		//RegisterRenderItem(renderItem);
	}

}

Particle::~Particle()
{
	if (renderItem != nullptr) {
		//DeregisterRenderItem(renderItem);
		renderItem->release();
	}
}

void Particle::integrate(double t)
{
	_cont += t;

	
	Vector3 resulting_accel = _force * _inv_mass;
	_vel += resulting_accel * t;
	

	//_vel += _accel * t;

	// Impose drag (damping)
	_vel *= powf(_damping, t);

	// Update position
	_pos.p += _vel*t;

	clearForce();

}

Particle* Particle::clone()
{
	Particle* p = new Particle(_pos.p, _vel, _accel,_mass, _duration, _damping, _type);
	return p;
}
