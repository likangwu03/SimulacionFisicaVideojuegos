#include "SceneP1.h"

SceneP1::SceneP1():Scene()
{
	numP = 10;
	PISTOL_VEL = 25;
	PISTOL_MASS = PISTOL_REAL_MASS * (PISTOL_REAL_VEL / PISTOL_VEL) * (PISTOL_REAL_VEL / PISTOL_VEL);
	
	PISTOL_g = 9.8 *   PISTOL_REAL_MASS/ PISTOL_MASS;


	g = Vector3(0, -2, 0);
}

void SceneP1::keyPress(unsigned char key)
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

void SceneP1::init()
{
}

void SceneP1::shoot()
{
	if (objsByGroup_[SFV::_grp_GENERAL].size() < numP) {
		Proyectil* aux= new Proyectil(cam->getTransform().p, cam->getDir()* PISTOL_VEL, g, 10);
		addObject(aux, SFV::_grp_GENERAL);
	}
}
