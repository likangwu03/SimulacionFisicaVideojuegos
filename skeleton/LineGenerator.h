#pragma once
#include "ParticleGenerator.h"
class LineGenerator :public ParticleGenerator
{
public:
	LineGenerator(ParticleSystem* system, int n_particle, Vector3 pos, Vector3 vel, double frequency, Particle* p = nullptr);

	void generateParticles() override;

	void update(double t) override;

	inline void setDuration(double d_) { d = d_; }

private:
	double d;
};

