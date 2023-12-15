#pragma once
#include "Scene.h"
#include "StaticObject.h"
#include "DynamicObject.h"
#include "SolidSystemP5.h"
class sceneP5 :public Scene
{
public:
	sceneP5(PxData data = PxData());
	virtual void keyPress(unsigned char key);

private:
	void create();

	SolidSystem* s;

};

