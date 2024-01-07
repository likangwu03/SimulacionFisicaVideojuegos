;

#pragma once
#include "Particle.h"
#include <cmath>
#include "checkML.h"
class LineParticle :public Particle
{
public:
	LineParticle( ParticleInfor infor,float r);
	void integrate(double t) override;
	virtual Particle* clone();

protected:
	float r;
	ParticleInfor i;
	virtual void createRender();


};


