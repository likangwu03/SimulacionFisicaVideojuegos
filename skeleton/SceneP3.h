
#pragma once
#include "Scene.h"
#include <vector>
#include "Proyectil.h"
#include "ParticleSystem.h"
#include "Fireword.h"
#include "TurnParticle.h"
#include "CircleGenerator.h"
#include "ParticleSystemP3.h"

class SceneP3 :public Scene
{
public:
	SceneP3();
	virtual void keyPress(unsigned char key);

private:
	void shoot();
	void firework(int t);
	void firework2(int t);

	ParticleSystemP3* s;
};

