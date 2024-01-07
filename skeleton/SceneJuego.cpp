#include "SceneJuego.h"

SceneJuego::SceneJuego(PxData data) :Scene(data)
{
	create();
	createSys();
}


void SceneJuego::createSys()
{
	SolidSystemPF* s1 = new SolidSystemPF(this);
	addSystem(s1);
	setSystemHandler(s1, "SolidSystem");

	ParticleSystemPF* s2 = new ParticleSystemPF(this);
	addSystem(s2);
	setSystemHandler(s2, "ParticleSystem");

	ControllerSystem* s3 = new ControllerSystem(this);
	addSystem(s3);
	setSystemHandler(s3, "ControllerSystem");

}

void SceneJuego::create()
{
	//Ball
	DynamicObject::ObjectInfor infor2;
	infor2.gPhysics = _data.gPhysics;
	infor2.gScene = _data.gScene;
	infor2.pos = Vector3(0, 10, 0);
	infor2.masa = 0.1;
	infor2.tam.x = 2;
	infor2.densidad = -1;
	Ball* b=new Ball(infor2);
	setHandler(_hdlr_BALL, b);
	addObject(b, SFV::_grp_SOLID);


	new Floor(this, { 0,0,0 }, PxQuat(0, PxVec3(0, 0, 1)), 80, 20, 50);
	
}
