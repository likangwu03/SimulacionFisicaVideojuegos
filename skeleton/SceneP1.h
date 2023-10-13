#pragma once
#include "Scene.h"
#include <vector>
#include "Proyectil.h"
#include "ParticleSystem.h"


class SceneP1 :public Scene
{
public:
	SceneP1();
	virtual void keyPress(unsigned char key);
	virtual void init();
public:
	const double PISTOL_REAL_MASS = 0.01;
	const double PISTOL_REAL_VEL = 380;

private:
	void shoot();
protected:
	int numP ;
	Vector3 g;

	double PISTOL_MASS;
	double PISTOL_VEL;
	double PISTOL_g;
};

