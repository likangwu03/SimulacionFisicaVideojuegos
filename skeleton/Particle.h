#pragma once
#include <PxPhysics.h>
#include "core.hpp"
#include "def.h"
#include "Object.h"
using namespace SFV;
using namespace physx;
class Particle :public Object
{

public:

	struct ParticleInfor {
		Vector3 Pos= Vector3(0);
		Vector3 Vel= Vector3(0);
		Vector3 accel = SFV::GRAVITY;
		double duration = DEFAULT_DURATION;
		double damping = SFV::DAMPING;
		ParticleType type = ParticleType::_particle_default;
		double masa = 1;
	};


	Particle(ParticleInfor info);



	Particle(Vector3 Pos, Vector3 Vel, Vector3 accel = Vector3(0), double masa=1, double duration = DEFAULT_DURATION, double damping = SFV::DAMPING, ParticleType type = ParticleType::_particle_default);
	~Particle();

	void integrate(double t) override;

	inline const Vector3 getPosition() { return _pos.p; }
	inline const Vector3 getVelocity() { return _vel; }
	inline const double getDuration() { return _duration; }
	inline const double getTime() { return _cont; }

	inline void setVel(Vector3 vel) { _vel = vel; }
	inline void setPos(Vector3 pos) { _pos.p = pos; }
	inline void setAccel(Vector3 accel) { _accel = accel; }
	inline void setDuration(double d) { _duration = d; }

	virtual Particle* clone();

	void removeRenderItem() {
		DeregisterRenderItem(renderItem);
		renderItem->release();
		renderItem = nullptr;
	}


	inline void addForce(const Vector3& f); inline void addForce(Vector3 f) {
		_force += f;
	}
	inline void clearForce() {
		_force *= 0.0;
	}

protected:
	ParticleType _type;
	Vector3 _vel;
	Vector3 _accel;
	PxTransform _pos;
	RenderItem* renderItem;
	double _damping;

	double _duration;
	double _cont;

	double _inv_mass;

	Vector3 _force;
};

