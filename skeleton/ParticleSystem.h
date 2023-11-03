#pragma once
#include "System.h"
#include "RenderUtils.hpp"
#include "def.h"
#include "Particle.h"
#include "ParticleGenerator.h"
#include <list>
#include "GaussianParticleGenerator.h"
#include "Fountain.h"
#include "CircleGenerator.h"
#include "TornadoSystem.h"
class Scene;
class ParticleSystem:public System {

protected:
	Vector3 _gravity;
	std::list <ParticleGenerator*> _particle_generators;
	std::list <Particle*> _particles;

public:
	// Creates a void system with a det. gravity
	ParticleSystem(Scene* scene,const Vector3& g = SFV::GRAVITY);

	virtual ~ParticleSystem() {};

	// Integrates the particles and checks for its lifetime, setc!
	void update(double t) override;

	void addGenerator(ParticleGenerator* g) {
		_particle_generators.push_back(g);
	}

	template <typename Valor>
	void addParticles(std::list<Valor*>& lista);

	void refresh();

	//template <typename Valor>
	void addParticle(Particle* p);
};