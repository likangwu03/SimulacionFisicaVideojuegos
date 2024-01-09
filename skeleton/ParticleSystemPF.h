#pragma once
#include "ParticleSystem.h"
#include "WhirlwindsForceGenerator.h"
#include "WindForceGenerator.h"
#include "AnchoredSpringFG.h"
#include "LineGenerator.h"
#include "LineParticle.h"


class ParticleSystemPF :public ParticleSystem
{
public:
	ParticleSystemPF(Scene* scene);

	~ParticleSystemPF() {};

	virtual void keyPress(unsigned char key);

	LineGenerator* getLine() { return line; }

	void createWinds(Vector3 p, Vector3 a, float k1, Vector3 v);

	void createFog(Vector3 p, Vector3 a, float f);

protected:
	LineGenerator* line;

	void create();
};

