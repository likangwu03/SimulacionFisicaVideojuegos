#include "SceneP2.h"
SceneP2::SceneP2() :Scene()
{
	auto s = new ParticleSystem(this);
	addSystem(s);
}

void SceneP2::keyPress(unsigned char key)
{
	switch (toupper(key))
	{
	case ' ':
	{
		firework();
		shoot();
		break;
	}
	default:

		break;
	}
}


void SceneP2::shoot()
{
	Particle::ParticleInfor infor;
	infor.Vel = Vector3(10, 4, 0);
	infor.duration = 8;
	infor.accel = Vector3(0);
	//infor.Pos = Vector3(0, 150, 100);
	TurnParticle* f = new TurnParticle(10, 0,180, infor);
	addObject(f);
}

void SceneP2::firework()
{
	Particle::ParticleInfor infor;
	infor.Vel = Vector3(0, 25, 0);
	infor.duration = 1;
	Fireword* f = new Fireword(3, 4, infor);
	addObject(f);
}

