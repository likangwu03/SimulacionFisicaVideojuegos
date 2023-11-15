#include "WindForceGenerator.h"
WindForceGenerator::WindForceGenerator(double k1, Vector3 windVel, double duration, Vector3 windArea) :ForceGenerator(WindForce, duration), windVel(windVel), k1(k1), airDensity(1.2), dragCoef(0.5), k2(0.1), windArea(windArea) {}

void WindForceGenerator::updateForce(Particle* particle)
{
	if (fabs(particle->getInvMass()) < 1e-10) return;


}
