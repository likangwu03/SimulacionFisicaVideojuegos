
#pragma once
#include "SolidSystem.h"
#include "WhirlwindsSolidForceGenerator.h"

#include "DragForceGenerator.h"
class SolidSystemPF :public SolidSystem
{
public:
	SolidSystemPF(Scene* scene);
	virtual void keyPress(unsigned char key);

	void createWinds(Vector3 p, Vector3 a, float k1, Vector3 v);


protected:
	WhirlwindsSolidForceGenerator* whirlwinds;

};



