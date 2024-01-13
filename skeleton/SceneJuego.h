
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
#include "Hole.h"
#include "Fan.h"




class SceneJuego :public Scene
{
public:
	struct Area {
		float w;
		float h;
		Vector3 p;
	};
public:
	enum State {INI,GAME,OVER};

	SceneJuego(PxData data = PxData());

	void NextLevel();

	virtual void update(double t);

	virtual void keyPress(unsigned char key);

	float getAngle() { return ctrl->getAngle(); }
	float getForce() { return ctrl->getForce(); }

	int getState() { return (int)state; }

private:
	const int MAX_LEVEL = 3;
	const Vector4 color = Vector4(1);

	State state;
	std::vector<PxVec3> Ball_pos_vector;
	std::vector<Area> Areas;

	int level = -1;
	bool next_level = false;


	void createSys();
	void create();

	void createLevels();
	void level1();
	void level2();
	void level3();
	void level4();

	SolidSystemPF* solid;
	ControllerSystem* ctrl;
	ParticleSystemPF* particle;


	void reset();

	void gameOver();

	void gameStart();

	void creatFan(Vector3 p,Vector3 area, float k, Vector3 v);

	void createBox(Vector3 p, Vector3 area, float r = 0);

};


