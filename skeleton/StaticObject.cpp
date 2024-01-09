#include "StaticObject.h"

StaticObject::StaticObject(ObjectInfor infor):Object(),_infor(infor)
{
	if (infor.default) {
		_rb = infor.gPhysics->createRigidStatic(PxTransform(infor.pos, infor.q));
		shape = CreateShape(PxBoxGeometry(infor.tam));
		_rb->setName(" ");

		_rb->attachShape(*shape);
		infor.gScene->addActor(*_rb);
		renderItem = new RenderItem(shape, _rb, infor.color);
	}
	
}

StaticObject::~StaticObject()
{
	_infor.gScene->removeActor(*_rb);
	if (renderItem != nullptr) {
		renderItem->release();
	}
}
