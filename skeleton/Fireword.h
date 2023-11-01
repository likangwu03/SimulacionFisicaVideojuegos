#pragma once
#include "Particle.h"
class FireworkSystem;

class Fireword:public Particle
{
public:
	Fireword(int num,int gen, int type,ParticleInfor infor);
	~Fireword();
	Particle* clone() override;
	int getGen() { return _gen; }


	//virtual void integrate(double t);

protected:
	virtual void createFirewordSystem();
	FireworkSystem* sys;
	Fireword* p;
	int _num;
	int _gen;
	int t;
};

