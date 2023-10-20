#include "SceneP1.h"

SceneP1::SceneP1():Scene()
{
	numP = 10;
	PISTOL_VEL = 70;
	PISTOL_MASS = PISTOL_REAL_MASS * (PISTOL_REAL_VEL / PISTOL_VEL) * (PISTOL_REAL_VEL / PISTOL_VEL);
	
	PISTOL_g = 9.8 * PISTOL_VEL/ PISTOL_REAL_VEL ;

	g = Vector3(0, -PISTOL_g, 0);

	auto s=new ParticleSystem(this);
	addSystem(s);


}

void SceneP1::keyPress(unsigned char key)
{
	switch(toupper(key))
	{
	case ' ':
	{
		firework();
		//shoot();
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

	//if (objsByGroup_[SFV::_grp_GENERAL].size() < numP) {
		Proyectil* aux= new Proyectil(cam->getTransform().p, cam->getDir()* PISTOL_VEL, g, PISTOL_MASS);
		addObject(aux, SFV::_grp_GENERAL);
	//}
}

void SceneP1::firework()
{
	Particle::ParticleInfor infor;
	infor.Vel = Vector3(0, 10, 0);
	Fireword* f = new Fireword(3, infor);

	((ParticleSystem*)getSystem(1))->addParticle(f);
}

