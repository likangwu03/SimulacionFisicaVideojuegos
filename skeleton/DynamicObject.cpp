#include "DynamicObject.h"

DynamicObject::DynamicObject(ObjectInfor infor) :Object()
{
	_infor = infor;

	if (!infor.model && infor.default) {
		create(); 
	}

}

DynamicObject::~DynamicObject()
{
	_infor.gScene->removeActor(*_rb);
	if (renderItem != nullptr) {
		renderItem->release();
	}

}

DynamicObject* DynamicObject::createOther(ObjectInfor infor)
{
	return new DynamicObject(infor);
}

void DynamicObject::integrate(double t)
{
	_cont += t;
}

void DynamicObject::create()
{
	_rb = _infor.gPhysics->createRigidDynamic(PxTransform(_infor.pos));
	_rb->setLinearVelocity(_infor.vel);
	_rb->setAngularVelocity(_infor.w);
	shape = CreateShape(PxBoxGeometry(_infor.tam));
	_rb->attachShape(*shape);
	_rb->setName(" ");
	_rb->setMass(_infor.masa);
	if (_infor.densidad != -1) {
		PxRigidBodyExt::updateMassAndInertia(*_rb, _infor.densidad);
		_infor.masa = _rb->getMass();
	}
	if (_infor.tensor != Vector3(-1)) {
	 _rb->setMassSpaceInertiaTensor(_infor.tensor);
	}
	_infor.gScene->addActor(*_rb);
	renderItem = new RenderItem(shape, _rb, _infor.color);
}
