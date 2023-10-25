#include "Fireword.h"
#include "FireworkSystem.h"
#include "Scene.h"
Fireword::Fireword(int num, int gen,ParticleInfor infor) :Particle(infor)
{
	p = nullptr;
	_num = num;
	_gen = gen;
	sys = nullptr;
}

Fireword::~Fireword()
{
	if (_gen > 0) {
		createFirewordSystem();
		sys->generate();
		delete sys;
	}
}

void Fireword::createFirewordSystem()
{
	p = clone();
	p->removeRenderItem();
	sys = new FireworkSystem(" ", (ParticleSystem*)scene_->getSystem(SFV::SystemId::_sys_PARTICLE),_num, _pos.p,_vel,0,(Fireword *) p);
}

Particle* Fireword::clone()
{
	ParticleInfor i;
	i.accel = _accel;
	i.damping = _damping;
	i.duration = _duration;
	i.masa = 1 / _inv_masa;
	i.Pos = _pos.p;
	i.type = _type;
	i.Vel = _vel;
	Particle* aux = new Fireword(_num, _gen - 1, i);
	return aux;
}
