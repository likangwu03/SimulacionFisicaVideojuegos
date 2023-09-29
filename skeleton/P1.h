#pragma once
#include "GameManager.h"
#include <vector>
#include "Proyectil.h"
class P1 :public GameManager
{
public:
	P1();
	virtual void keyPress(unsigned char key);
	virtual void update(double t);
	virtual void init();

private:
	void shoot();
protected:
	std::vector< Proyectil*> mVector;
	int numP ;
	Vector3 g;
	double vel;
};

