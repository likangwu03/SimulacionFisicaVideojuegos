#include "SolidSystemPF.h"
#include "Scene.h"
SolidSystemPF::SolidSystemPF(Scene* scene) :SolidSystem(scene)
{


	/*
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
	*/

	DragForceGenerator* drag = new DragForceGenerator();
	drag->setDrag(0.05, 0);
	addForce(drag);

}

void SolidSystemPF::keyPress(unsigned char key)
{

}

void SolidSystemPF::createWinds(Vector3 p, Vector3 a, float k1, Vector3 v)
{
	WindSolidForceGenerator* wind = new WindSolidForceGenerator(k1, v, a, p);
	addForce(wind);
}

void SolidSystemPF::createWhirlwinds(double K, double Y, double k1, Vector3 area, Vector3 pos)
{
	WhirlwindsSolidForceGenerator* whirlwinds = new WhirlwindsSolidForceGenerator(K, Y, k1, { 0,0,0 }, area, pos);
	addForce(whirlwinds);
}



