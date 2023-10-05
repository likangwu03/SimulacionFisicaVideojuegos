#include "Proyectil.h"

Proyectil::Proyectil(Vector3 Pos, Vector3 Vel, Vector3 ace, double masa,double t) :Particle(Pos, Vel,ace)
{
	inv_masa = 1/masa;
	lifeTime = t;
	cont = 0;
}

void Proyectil::integrate(double t)
{
	Particle::integrate(t);
	cont += t;
	if (cont > lifeTime) {
		setAlive(false);
	}
}
