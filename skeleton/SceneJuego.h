
#pragma once
#include "Scene.h"

#include "SolidSystemPF.h"
#include "ParticleSystemPF.h"
#include "ControllerSystem.h"

#include "StaticObject.h"
#include "DynamicObject.h"
#include "SolidSystemP5.h"
#include "Floor.h"
#include "Ball.h"
class SceneJuego :public Scene
{
public:
	SceneJuego(PxData data = PxData());
private:
	void createSys();
	void create();

	SolidSystem* s;

};


