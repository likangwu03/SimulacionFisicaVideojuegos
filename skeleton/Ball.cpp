#include "Ball.h"

Ball::Ball(ObjectInfor infor):DynamicObject(infor){
	create();
}

void Ball::create()
{

	//PxMaterial* gMaterial = _infor.gPhysics->createMaterial(1, 1, 0.7);

	_rb = _infor.gPhysics->createRigidDynamic(PxTransform(_infor.pos));
	_rb->setLinearVelocity(_infor.vel);
	_rb->setAngularVelocity(_infor.w);
	PxSphereGeometry a;
	a.radius = _infor.tam.x;
	shape = CreateShape(a);
	_rb->attachShape(*shape);
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
