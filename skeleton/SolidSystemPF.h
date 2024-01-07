
#pragma once
#include "SolidSystem.h"
#include "WhirlwindsSolidForceGenerator.h"

#include "DragForceGenerator.h"
class SolidSystemPF :public SolidSystem
{
public:
	SolidSystemPF(Scene* scene);
	virtual void keyPress(unsigned char key);
protected:
	WhirlwindsSolidForceGenerator* whirlwinds;

};



