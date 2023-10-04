#pragma once
#include "Particle.h"
class Proyectil:public Particle
{
public:
	Proyectil(Vector3 Pos, Vector3 Vel, Vector3 ace,double masa,double t=1);
	virtual void integrate(double t);



protected:
	double inv_masa;
	double lifeTime;
	double cont;

};

