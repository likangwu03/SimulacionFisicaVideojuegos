#include "P1.h"

P1::P1():GameManager()
{
	numP = 10;
	g = Vector3(0, -2, 0);
	vel = 30;
}

void P1::keyPress(unsigned char key)
{
	switch(toupper(key))
	{
	//case 'B': break;
	//case ' ':	break;
	case ' ':
	{
		shoot();
		break;
	}
	default:

		break;
	}
}

void P1::update(double t)
{
	for (auto p : mVector) {
		p->integrate(t);
	}
}

void P1::init()
{
}

void P1::shoot()
{
	if (mVector.size() < numP) {
		Proyectil* aux= new Proyectil(cam->getTransform().p, cam->getDir()* vel, g, 10);
		mVector.push_back(aux);
	}
}
