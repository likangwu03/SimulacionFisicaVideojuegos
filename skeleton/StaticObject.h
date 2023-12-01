#pragma once
#include "Object.h"
#include <PxPhysics.h>
#include "RenderUtils.hpp"
#include "core.hpp"
using namespace physx;
class StaticObject :public Object
{
public:
	struct ObjectInfor {
		Vector3 pos = Vector3(0);
		Vector3 tam = Vector3(10);
		double duration = -1;
		double masa = 10;
		int type;
		Scene* scene=nullptr;
		PxPhysics* gPhysics = nullptr;
		PxScene* gScene = nullptr;
		Vector4 color = Vector4(1);
	};

	StaticObject(ObjectInfor infor );
	PxRigidStatic* getActor() { return _rb; }
protected:
	RenderItem* renderItem;
	PxRigidStatic* _rb;
	PxShape* shape;

};

