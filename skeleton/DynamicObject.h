#pragma once
#include "Object.h"
#include <PxPhysics.h>
#include "RenderUtils.hpp"
#include "core.hpp"
using namespace physx;
class DynamicObject :public Object
{
public:
	struct ObjectInfor {
		Vector3 pos = Vector3(0);
		Vector3 tam = Vector3(10);
		Vector3 vel = Vector3(0);
		Vector3 accel = Vector3(0);
		double duration = -1;
		double masa = 10;
		int type;
		Scene* scene = nullptr;
		PxPhysics* gPhysics = nullptr;
		PxScene* gScene = nullptr;
	};

	DynamicObject(ObjectInfor infor);
	PxRigidStatic* getActor() { return _rb; }
protected:
	RenderItem* renderItem;
	PxRigidStatic* _rb;
	PxShape* shape;
};

