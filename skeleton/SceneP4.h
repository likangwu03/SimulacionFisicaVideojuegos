#pragma once
#include "Scene.h"
#include "ParticleSystemP4.h"
class SceneP4 :public Scene
{
public:
	SceneP4();
	virtual void keyPress(unsigned char key);
protected:
	ParticleSystemP4* s;
};

