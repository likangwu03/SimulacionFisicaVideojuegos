#pragma once
#include "Particle.h"
class FireworkSystem;
class Fireword:public Particle
{
public:
	Fireword(int num, ParticleInfor infor);
	~Fireword();
protected:
	virtual void createFirewordSystem();
	FireworkSystem* sys;
	Particle* p;
	int _num;
};

