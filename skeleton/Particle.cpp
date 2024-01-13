#include "Particle.h"
#include "checkML.h"
Particle::Particle(ParticleInfor info):Object(), _vel(info.Vel), _accel(info.accel), _duration(info.duration),
_damping(info.damping), _type(info.type), _cont(0), renderItem(nullptr), _force(Vector3(0)) ,color(info.color),_r(info.r){
	_mass = info.masa;

	my_info = info;

	if (info.masa == 0)_inv_mass = 0;
	else _inv_mass = (1 / info.masa);

	_pos = physx::PxTransform(info.Pos);

	createRender();
	

}

Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 accel,double masa, double duration,double damping, ParticleType type):Object(),
_vel(Vel),_accel(accel),_duration(duration),_damping(damping), _type(type),_mass(masa), _inv_mass(1 / masa), _cont(0), renderItem(nullptr), _force(Vector3(0))
{
	_pos = physx::PxTransform(Pos);

	createRender();

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
	//_pos.p += _vel * t;
	
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
	/*ParticleInfor i;
	i.Pos = _pos.p;
	i.Vel = _vel;
	i.accel = _accel;
	i.color = color;
	i.masa = _mass;
	i.duration = _duration;
	i.*/
	Particle* p = new Particle(my_info);
	return p;
}


void Particle::createRender() {
	if (_type == ParticleType::_particle_default) {
		PxSphereGeometry a;
		a.radius = _r;
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, color);
	}
	else if (_type == ParticleType::_particle_F1) {
		PxSphereGeometry a;
		a.radius = 2.75;
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, Vector4(0.1, 0.5, 0.9, 1));
	}
	else if (_type == ParticleType::_particle_F2) {
		PxSphereGeometry a;
		a.radius = 0.3;
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, Vector4(0.9, 0.1, 0.1, 1));
	}
	else if (_type == ParticleType::_particle_mass) {
		PxSphereGeometry a;
		Vector4 color;
		if (_mass > 100){
			a.radius = 1;
			color = Vector4(1, 0, 0, 1);
		}
		else if (_mass > 1) {
			a.radius = _mass / 100.0;
			if (a.radius < 0.1)a.radius = 0.1;
			if (_mass > 50) {
				color = Vector4(_mass / 50.0, 0, _mass / 100.0, 1);
			}
			else {
				color = Vector4(_mass / 100.0, 0, _mass / 50.0, 1);
			}
			
		}
		else {
			a.radius = 0.1;
			color = Vector4(0, 0, 1, 1);
		}

	
		PxShape* shape = CreateShape(a);
		renderItem = new RenderItem(shape, &_pos, color);
	}

}