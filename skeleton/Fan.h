
#pragma once
#include <PxPhysics.h>
#include "core.hpp"
#include "def.h"
#include "Object.h"
#include "StaticObject.h"
#include "DynamicObject.h"
#include "BoxParticle.h"

using namespace SFV;
using namespace physx;
class Scene;


class Fan :public Object {
public:
	

	Fan(Scene* s, Vector3 pos, float speed=100, float w=25, float h=3, float d=3, Vector4 c = Vector4(0.5, 0.5, 0.5, 1));

	~Fan();

	virtual void integrate(double t);


protected:
	float width;
	float height;
	float depth;
	Vector3 _pos;
	Vector4 color;
	float _speed;

	float _degree;

	BoxParticle* obj1;
	BoxParticle* obj2;
	
};

