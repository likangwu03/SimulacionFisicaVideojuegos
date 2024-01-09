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
		bool model = false;
		bool default = false;
		Vector3 pos = Vector3(0);
		Vector3 tam = Vector3(3);
		Vector3 vel = Vector3(0);
		Vector3 w = Vector3(0);
		double duration = -1;
		double masa = 10;
		double densidad = 1;
		Vector3 tensor = Vector3(-1);
		int type;
		Scene* scene = nullptr;
		PxPhysics* gPhysics = nullptr;
		PxScene* gScene = nullptr;
		Vector4 color = Vector4(1);
	};

	DynamicObject(ObjectInfor infor);

	~DynamicObject();

	ObjectInfor getInfor() { return _infor; }

	virtual DynamicObject* createOther(ObjectInfor infor);

	virtual void integrate(double t);

	double getDuration() { return _infor.duration; }
	double getTime() { return _cont; }

	Vector3 getTam() { return _infor.tam; }

	PxRigidDynamic* getRigid() { return _rb; }

protected:
	virtual void create();

	RenderItem* renderItem = nullptr;
	PxRigidDynamic* _rb = nullptr;
	PxShape* shape = nullptr;
	ObjectInfor _infor;

	double _cont = 0;
};

