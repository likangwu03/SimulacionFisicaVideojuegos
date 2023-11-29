#include "BuoyancyForceGenerator.h"

BuoyancyForceGenerator::BuoyancyForceGenerator(float h, float v, float d):ForceGenerator(),
_height(h),_volume(v),_liquid_density(d)
{
	Particle::ParticleInfor infor;
	infor.duration = -1;
	infor.Vel = { 0,0,0 };
	infor.Pos = { 0,0,0 };
	_liquid_particle = new BoxParticle(infor, 100, 1, 100);
}

void BuoyancyForceGenerator::updateForce(Particle* particle, double t)
{
	float h = particle->getPosition().y;
	float h0 = _liquid_particle->getPosition().y;

	Vector3 f(0, 0, 0);
	float immersed = 0.0;

	if (h - h0 > _height * 0.5) {
		immersed = 0.0;
	}
	else if (h0 - h > _height * 0.5) {
		immersed = 1.0;
	}
	else {
		immersed = (h0 - h) / _height + 0.5;
	}

	f.y = _liquid_density * _volume * immersed * 9.8;
	particle->addForce(f);
}

BuoyancyForceGenerator::~BuoyancyForceGenerator()
{
	delete _liquid_particle;
}
