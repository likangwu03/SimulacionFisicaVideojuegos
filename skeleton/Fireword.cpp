#include "Fireword.h"
#include "FireworkSystem.h"
#include "Scene.h"
#include "checkML.h"
Fireword::Fireword(int num, int gen,int type,ParticleInfor infor) :Particle(infor)
{
	p = nullptr;
	_num = num;
	_gen = gen;
	t = type;
	sys = nullptr;
}

Fireword::~Fireword()
{
	if (_gen > 0) {
		createFirewordSystem();
		switch (t)
		{
		case 1:
			sys->generateParticles1();
			break;
		case 2:
			sys->generateParticles2();
			break;
		case 3:
			sys->generateParticles3();
			break;
		case 4:
			sys->generateParticles4();
			break;
	
		}
		
	}
	delete sys;
}
/*
void Fireword::integrate(double t)
{
		_cont += t;

		_vel += _accel * t;

		// Impose drag (damping)
		_vel *= powf(_damping, t);

		// Update position
		_pos.p += _vel * t;

		if (_cont > _duration) {
			setAlive(false);
		}
}
*/

void Fireword::createFirewordSystem()
{
	p = (Fireword*)clone();
	p->removeRenderItem();
	p->_gen--;
	p->setContext(scene_);
	sys = new FireworkSystem(" ", (ParticleSystem*)scene_->getSystem("ParticleSystem"), _num, _pos.p, _vel, 0, (Fireword*)p);
}

Particle* Fireword::clone()
{
	ParticleInfor i;
	i.accel = _accel;
	i.damping = _damping;
	i.duration = _duration;
	i.masa = 1 / _inv_mass;
	i.Pos = _pos.p;
	i.type = _type;
	i.Vel = _vel;
	Particle* aux = new Fireword(_num, _gen,t, i);
	return aux;
}
