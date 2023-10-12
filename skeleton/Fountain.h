#pragma once
#include "ParticleGenerator.h"

class Fountain: public ParticleGenerator
{
public:
	Fountain(std::string name, Vector3 pos,  Vector3 vel,Vector3 g, Particle* p=nullptr);

	virtual std::list<Particle*> generateParticles();

private:
	void ini_rnd();
};

