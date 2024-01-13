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

#include "ParticleForceRegistry.h"

class Scene;
class ParticleSystem:public System {
protected:
	Vector3 _gravity;
	std::vector <ParticleGenerator*> _particle_generators;
	std::list <Particle*> _particles;


	std::list <ForceGenerator*> _forceGenerators;
	ParticleForceRegistry particleForceRegistry;

public:
	// Creates a void system with a det. gravity
	ParticleSystem(Scene* scene,const Vector3& g = SFV::GRAVITY);

	virtual ~ParticleSystem();

	// Integrates the particles and checks for its lifetime, setc!
	void update(double t) override;

	void addGenerator(ParticleGenerator* g) {
		_particle_generators.push_back(g);
	}

	void addForce(ForceGenerator* g);

	void removeForce(ForceGenerator* g);

	void refresh();

	//template <typename Valor>
	void addParticle(Particle* p, bool force=true);
	void addParticle2(Particle* p,bool force=false);
};