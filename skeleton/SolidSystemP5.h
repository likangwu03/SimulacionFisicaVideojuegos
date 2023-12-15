#pragma once
#include "SolidSystem.h"
#include "WhirlwindsSolidForceGenerator.h"
class SolidSystemP5 :public SolidSystem
{
public:
	SolidSystemP5(Scene* scene);
	virtual void keyPress(unsigned char key);
protected:
	WhirlwindsSolidForceGenerator* whirlwinds;

};

