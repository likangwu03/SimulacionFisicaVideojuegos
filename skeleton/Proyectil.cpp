#include "Proyectil.h"

Proyectil::Proyectil(Vector3 Pos, Vector3 Vel, Vector3 ace, double Masa) :Particle(Pos, Vel,ace)
{
	masa = Masa;
}

void Proyectil::integrate(double t)
{
	Particle::integrate(t);
	//vel += gravedad * t;
}
