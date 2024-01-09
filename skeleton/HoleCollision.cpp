#include "HoleCollision.h"
HoleCollision::HoleCollision(ObjectInfor infor) :StaticObject(infor) {
	create();
}

void HoleCollision::create()
{

	//PxMaterial* gMaterial = _infor.gPhysics->createMaterial(1, 1, 0.7);
	_rb = _infor.gPhysics->createRigidStatic(PxTransform(_infor.pos, _infor.q));
	_rb->setName("hole");

	shape = CreateShape(PxBoxGeometry(_infor.tam));
	_rb->attachShape(*shape);
	_infor.gScene->addActor(*_rb);
	renderItem = new RenderItem(shape, _rb, _infor.color);

}
