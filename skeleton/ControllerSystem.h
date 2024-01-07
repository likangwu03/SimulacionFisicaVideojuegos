#pragma once
#include "System.h"
#include "Ball.h"
#include "LineGenerator.h"
#include <cmath>
class ControllerSystem :public System
{
public:
	ControllerSystem(Scene* scene);

	void iniObj();

	virtual void update(double t);
	void keyPress(unsigned char key) override;

	void handleMouse(int button, int state, int x, int y)override;
	void handleMotion(int x, int y)override;

private:
	const float maxForce = 15000;
	const float minForce = 2000;
	const float v = 35;
	const double cont_t = 1;

	const double minVel = 0.15; 

	const float _d = 5;

	const float p_d = 1.5;
	const float p_ini = 0.5;


	
	double cont = 0;
	float force = 5000;
	PxVec3 ball_pos_hit;
	PxVec3 ball_pos;
	double angleInDegrees = 0;

	PxVec3 dir;

	bool canHit;

	bool hasHit=false;

	Ball* ball;
	Camera* camera;
	LineGenerator* line;




	void adjustsCameraPos();

};

