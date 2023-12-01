#include "StaticObject.h"

StaticObject::StaticObject(ObjectInfor infor):Object()
{
	_rb = infor.gPhysics->createRigidStatic(PxTransform(infor.pos));
	shape = CreateShape(PxBoxGeometry(infor.tam));
	_rb->attachShape(*shape);
	infor.gScene->addActor(*_rb);
	renderItem = new RenderItem(shape, _rb, infor.color);
}
