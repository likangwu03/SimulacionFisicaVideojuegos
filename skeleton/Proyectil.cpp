#include "Proyectil.h"

Proyectil::Proyectil(Vector3 Pos, Vector3 Vel, Vector3 ace, double masa,double t) :Particle(Pos, Vel,ace,masa,t)
{
}

void Proyectil::integrate(double t){
	Particle::integrate(t);
	if (_cont > _duration) {
		setAlive(false);
	}
}
