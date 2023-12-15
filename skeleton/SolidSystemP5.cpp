#include "SolidSystemP5.h"
#include "Scene.h"

SolidSystemP5::SolidSystemP5(Scene* scene):SolidSystem(scene)
{

	DynamicObject::ObjectInfor i;
	i.model = true;
	i.duration = 5;
	i.scene = _scene;
	i.gPhysics = _scene->getPhysics();
	i.gScene = _scene->getGScene();
	i.masa = 1;
	i.color = Vector4(0.1, 0.4, 0.5, 0.5);
	i.tensor = Vector3(0, 0, 0);
	DynamicObject* obj = new DynamicObject(i);

	AreaSRGenerator* g = new AreaSRGenerator(this, { 0,10,0 }, 5, 0.3, { 150,150,150 }, obj);
	addGenerator(g);

	whirlwinds = new WhirlwindsSolidForceGenerator(2, 10, 100, { 0,0,0 }, { 200,250,200 }, { 0,0,0 });
	//whirlwinds = new WhirlwindsSolidForceGenerator(50, 10, 100, { 0,0,0 }, { 60,250,60 }, { 0,0,0 });
	addForce(whirlwinds);

}

void SolidSystemP5::keyPress(unsigned char key)
{
	switch (toupper(key))
	{
	case '1':
		whirlwinds->setActive(!whirlwinds->getActive());
		std::cout << "whirlwinds: " << whirlwinds->getActive() << "\n";
		break;
	}
}
