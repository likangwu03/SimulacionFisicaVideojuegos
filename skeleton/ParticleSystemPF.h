#pragma once
#include "ParticleSystem.h"

#include "WhirlwindsForceGenerator.h"
#include "WindForceGenerator.h"
#include "AnchoredSpringFG.h"

#include "LineGenerator.h"
#include "LineParticle.h"
#include "FogGenerator.h"
#include "FireworkGenerator.h"

#include "BoxParticle.h"
#include "Fireword.h"

#include <vector>

class ParticleSystemPF :public ParticleSystem
{
public:
	ParticleSystemPF(Scene* scene);

	~ParticleSystemPF() {};

	virtual void keyPress(unsigned char key);

	LineGenerator* getLine() { return line; }

	void createWinds(Vector3 p, Vector3 a, float k1, Vector3 v);

	void createFog(Vector3 p, Vector3 a, float f,int num,int save=-1);

	void activeFog(int level);

	void offFog(int level);

	void createWhirlwinds(double K, double Y, double k1, Vector3 area, Vector3 pos);

	void createMuelle(Vector3 pos);

	void setActiveFirework(bool a){ firework->setActive(a); }

protected:
	LineGenerator* line;


	std::vector<FogGenerator*> fogs;

	FireworkGenerator* firework;

	void create();
};

