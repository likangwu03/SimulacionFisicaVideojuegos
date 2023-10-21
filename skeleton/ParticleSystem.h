#pragma once
#include "System.h"
#include "RenderUtils.hpp"
#include "def.h"
#include "Particle.h"
#include "ParticleGenerator.h"
#include <list>
#include "GaussianParticleGenerator.h"
#include "Fountain.h"
class Scene;
class ParticleSystem:public System {

protected:
	Vector3 _gravity;
	std::vector <Particle*> _particles;
	std::list <ParticleGenerator*> _particle_generators;

public:
	// Creates a void system with a det. gravity
	ParticleSystem(Scene* scene,const Vector3& g = SFV::GRAVITY);

	virtual ~ParticleSystem() {};

	// Integrates the particles and checks for its lifetime, setc!
	void update(double t) override;

	void addParticles(std::list<Particle*>& lista);

	void addParticle(Particle* p);
};