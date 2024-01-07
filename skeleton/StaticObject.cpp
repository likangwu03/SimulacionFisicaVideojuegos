#include "StaticObject.h"

StaticObject::StaticObject(ObjectInfor infor):Object(),infor(infor)
{
	_rb = infor.gPhysics->createRigidStatic(PxTransform(infor.pos,infor.q));
	shape = CreateShape(PxBoxGeometry(infor.tam));
	_rb->attachShape(*shape);
	infor.gScene->addActor(*_rb);
	renderItem = new RenderItem(shape, _rb, infor.color);
}

StaticObject::~StaticObject()
{
	infor.gScene->removeActor(*_rb);
	if (renderItem != nullptr) {
		renderItem->release();
	}
}
