#pragma once
#include <PxPhysics.h>
#include "core.hpp"
#include "def.h"
#include "Object.h"
#include "StaticObject.h"
#include "HoleCollision.h"
using namespace SFV;
using namespace physx;
class Scene;


class Hole :public Object {
public:
	struct WallInfor
	{
		bool left = true;
		bool right = true;
		bool top = true;
		bool down = true;
	};

	const float HOLE_TAM = 7.5;

	Hole(Scene* s, Vector3 pos, PxQuat q, float w, float h, float d,WallInfor i = WallInfor(), Vector4 c = Vector4(0.3, 0.7, 0.8, 1));

	~Hole();

protected:
	const float tam_r=0.01;
	float width;
	float height;
	float depth;
	Vector3 _pos;
	Vector4 color;
	PxQuat q;

	StaticObject* hole;
	std::vector< StaticObject*> walls;
	std::vector< StaticObject*> floors;
	const float wall_tam = 4;
	void createWall(Vector3 pos, Vector3 tam);
};


