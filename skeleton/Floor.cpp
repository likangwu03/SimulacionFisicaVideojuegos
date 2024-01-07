#include "Floor.h"
#include "Scene.h"
Floor::Floor(Scene* s,Vector3 pos, PxQuat q, float w, float h,float d, WallInfor i, Vector4 c) :Object(), _pos(pos), width(w), height(h), depth(d), color(c),q(q)
{
	setContext(s);
	StaticObject::ObjectInfor obj_i;
	obj_i.color = color;
	obj_i.scene = scene_;
	obj_i.gPhysics = scene_->getPhysics();
	obj_i.gScene = scene_->getGScene();
	obj_i.pos = _pos;
	obj_i.tam = Vector3(width, height, depth);
	obj_i.q = q;
	floor = new StaticObject(obj_i);

	if (i.left) createWall(_pos + Vector3(width, height, 0), Vector3(wall_tam, wall_tam, depth+ wall_tam));


	if (i.right) createWall(_pos + Vector3(-width, height, 0), Vector3(wall_tam, wall_tam, depth+ wall_tam));


	if (i.top) createWall(_pos + Vector3(0, height, depth), Vector3(width+ wall_tam, wall_tam, wall_tam));

	if (i.donw) createWall(_pos + Vector3(0, height, -depth), Vector3(width+ wall_tam, wall_tam, wall_tam));


}

Floor::~Floor()
{
	delete floor;
	for (auto obj : walls) {
		delete obj;
	}
}

void Floor::createWall(Vector3 pos, Vector3 tam)
{
	StaticObject::ObjectInfor obj_i;
	obj_i.color = color;
	obj_i.scene = scene_;
	obj_i.gPhysics = scene_->getPhysics();
	obj_i.gScene = scene_->getGScene();
	obj_i.pos = pos;
	obj_i.tam = tam;
	obj_i.q = q;
	StaticObject* w = new StaticObject(obj_i);
	walls.push_back(w);
}
