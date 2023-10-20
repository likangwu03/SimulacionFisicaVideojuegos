#include "Fireword.h"
#include "FireworkSystem.h"
#include "Scene.h"
Fireword::Fireword(int num, ParticleInfor infor) :Particle(infor)
{
	p = nullptr;
	_num = num;
}

Fireword::~Fireword()
{
	createFirewordSystem();
	sys->generate();
	delete sys;
}

void Fireword::createFirewordSystem()
{
	sys = new FireworkSystem(" ", (ParticleSystem*)scene_->getSystem(SFV::SystemId::_sys_PARTICLE),_num, _pos.p,_vel,0, p);
}
