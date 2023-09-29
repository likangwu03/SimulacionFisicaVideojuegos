#pragma once
#include "RenderUtils.hpp"
class GameManager
{
public:
	GameManager() { cam = GetCamera(); };
	virtual void keyPress(unsigned char key) {};
	virtual void update(double t){};
	virtual void init(){};
protected:
	Camera* cam;
};

