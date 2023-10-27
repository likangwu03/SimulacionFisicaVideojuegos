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
		shoot();
		break;
	case '1':
		firework(1);
		break;
	case '2':
		firework(2);
		break;
	case '3':
		firework(3);
	case '4':
		firework(4);
		break;
	case '5':
		firework2(1);
		break;
	case '6':
		firework2(2);
		break;
	case '7':
		firework2(3);
	case '8':
		firework2(4);
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

void SceneP2::firework(int t)
{
	Particle::ParticleInfor infor;
	infor.Vel = Vector3(0, 20, 0);
	infor.duration = 1;
	infor.type = _particle_F1;
	//infor.accel = Vector3(0);
	Fireword* f = new Fireword(12, 1,t, infor);
	addObject(f);
}

void SceneP2::firework2(int t)
{
	Particle::ParticleInfor infor;
	infor.Vel = Vector3(0, 20, 0);
	infor.duration = 1;
	infor.type = _particle_F2;
	//infor.accel = Vector3(0);
	Fireword* f = new Fireword(12, 2, t, infor);
	addObject(f);
}

