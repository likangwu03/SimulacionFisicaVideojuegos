#include "sceneP5.h"

sceneP5::sceneP5(PxData data):Scene(data)
{
	create();
}

void sceneP5::create()
{

	s = new SolidSystemP5(this);

	addSystem(s);
	setSystemHandler(s, "SolidSystem");

	StaticObject::ObjectInfor infor1;
	infor1.gPhysics = _data.gPhysics;
	infor1.gScene = _data.gScene;
	infor1.tam = Vector3(100, 5, 100);

	infor1.color = Vector4(0.5, 0.5, 0.5, 1);
	new StaticObject(infor1);

	DynamicObject::ObjectInfor infor2;

	infor2.gPhysics = _data.gPhysics;
	infor2.gScene = _data.gScene;
	infor2.pos = Vector3(0, 10, 0);
	infor2.masa = 1;
	new DynamicObject(infor2);
}
void sceneP5::keyPress(unsigned char key)
{
	s->keyPress(key);
}