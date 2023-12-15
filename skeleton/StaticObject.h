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
		Scene* scene=nullptr;
		PxPhysics* gPhysics = nullptr;
		PxScene* gScene = nullptr;
		Vector4 color = Vector4(1);
	};

	StaticObject(ObjectInfor infor );
protected:
	RenderItem* renderItem;
	PxRigidStatic* _rb;
	PxShape* shape;

};

