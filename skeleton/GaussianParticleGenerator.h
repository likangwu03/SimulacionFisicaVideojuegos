#pragma once
#include "ParticleGenerator.h"

class GaussianParticleGenerator : public ParticleGenerator
{
public:
	GaussianParticleGenerator(ParticleSystem* system, int n_particle, Vector3 pos, Vector3 vel, double frequency,  Particle* p = nullptr, Vector3 g=SFV::GRAVITY);


	void generateParticles() override;

	void update(double t) override;

protected:
	std::vector< std::normal_distribution<float>> normal_distributions;
	
	void addNormalDistribution(float mean,float deviation);

	void setDeviationVel(float deviation);
	
};

