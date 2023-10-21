#pragma once
#include "Particle.h"
class FireworkSystem;


class Fireword:public Particle
{
public:
	Fireword(int num,int gen, ParticleInfor infor);
	~Fireword();
	Particle* clone() override;
protected:
	virtual void createFirewordSystem();
	FireworkSystem* sys;
	Particle* p;
	int _num;
	int _gen;
};

