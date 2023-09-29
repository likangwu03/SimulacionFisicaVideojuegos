#pragma once
#include "Particle.h"
class Proyectil:public Particle
{
public:
	Proyectil(Vector3 Pos, Vector3 Vel, Vector3 ace,double Masa);
	virtual void integrate(double t);



protected:
	double masa;
	Vector3 gravedad;

};

