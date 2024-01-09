#pragma once
#include <PxPhysics.h>
#include "core.hpp"
#include "def.h"
#include "Object.h"
#include "StaticObject.h"
using namespace SFV;
using namespace physx;
class Scene;


class Floor :public Object{
public:
	struct WallInfor
	{
		bool left=true;
		bool right=true;
		bool top=true;
		bool down=true;
	};

	Floor(Scene* s,Vector3 pos, PxQuat q, float w,float h,float d, WallInfor i = WallInfor(),Vector4 c = Vector4(0.3, 0.7, 0.8, 1));

	~Floor();

protected:
	float width;
	float height;
	float depth;
	Vector3 _pos;
	Vector4 color;
	PxQuat q;

	StaticObject* floor;
	std::vector< StaticObject*> walls;
	const float wall_tam = 4;
	void createWall(Vector3 pos, Vector3 tam);
};

