#pragma once
#include "GaussianParticleGenerator.h"
#include "Fireword.h"
class FireworkSystem : public GaussianParticleGenerator
{
public:
	FireworkSystem(std::string name, ParticleSystem* system, int n_particles, Vector3 pos, Vector3 vel, double frequency, Fireword* p = nullptr);

	void generateParticles1();
	void generateParticles2();
	void generateParticles3();
	void generateParticles4();

protected:
	Fireword* fireword;
	std::uniform_real_distribution<float> angulo;
};


