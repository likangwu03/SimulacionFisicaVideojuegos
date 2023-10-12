#pragma once
#include "RenderUtils.hpp"
#include "def.h"
#include "Particle.h"
#include "ParticleGenerator.h"

#include <list>

class ParticleSystem {

protected:
	Vector3 _gravity;

	std::list <Particle*> _particles;
	std::list <ParticleGenerator*> _particle_generators;

public:
	// Creates a void system with a det. gravity
	ParticleSystem(const Vector3& g = SFV::GRAVITY);

	virtual ~ParticleSystem() {};

	// Integrates the particles and checks for its lifetime, setc!
	void update(double t);


};