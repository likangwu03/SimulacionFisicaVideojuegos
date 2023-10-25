#pragma once
#include "Scene.h"
#include <vector>
#include "Proyectil.h"
#include "ParticleSystem.h"
#include "Fireword.h"
#include "TurnParticle.h"
#include "CircleGenerator.h"

class SceneP2 :public Scene
{
public:
	SceneP2();
	virtual void keyPress(unsigned char key);

private:
	void shoot();
	void firework();
};

