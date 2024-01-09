#include "Hole.h"
#include "Scene.h"
Hole::Hole(Scene* s, Vector3 pos, PxQuat q, float w, float h, float d, WallInfor i, Vector4 c) :Object(), _pos(pos), width(w), height(h), depth(d), color(c), q(q){
	setContext(s);

	StaticObject::ObjectInfor hole_i;
	hole_i.color = Vector4(0,0,0,1);
	hole_i.scene = scene_;
	hole_i.gPhysics = scene_->getPhysics();
	hole_i.gScene = scene_->getGScene();
	hole_i.pos = _pos - Vector3(0, HOLE_TAM, 0);
	hole_i.tam = Vector3(HOLE_TAM - tam_r, HOLE_TAM, HOLE_TAM - tam_r);

	hole = new HoleCollision(hole_i);

	StaticObject::ObjectInfor obj_i;
	obj_i.color = color;
	obj_i.scene = scene_;
	obj_i.gPhysics = scene_->getPhysics();
	obj_i.gScene = scene_->getGScene();
	obj_i.pos = _pos+Vector3(0,0, HOLE_TAM/2+ depth/2);
	obj_i.tam = Vector3(width - tam_r, height, depth/2 - HOLE_TAM/2 - tam_r);
	obj_i.q = q;
	floors.push_back(new StaticObject(obj_i));

	obj_i.pos = _pos - Vector3(0, 0, HOLE_TAM/2 + depth / 2);
	floors.push_back(new StaticObject(obj_i));

	
	obj_i.pos = _pos+Vector3(HOLE_TAM/2+ width/2, 0, 0);
	obj_i.tam = Vector3((width- HOLE_TAM)/2, height, depth);
	floors.push_back(new StaticObject(obj_i));

	obj_i.pos = _pos - Vector3(HOLE_TAM / 2 + width / 2, 0, 0);
	floors.push_back(new StaticObject(obj_i));


	if (i.left) createWall(_pos + Vector3(width, height, 0), Vector3(wall_tam-tam_r, wall_tam , depth- wall_tam));


	if (i.right) createWall(_pos + Vector3(-width, height, 0), Vector3(wall_tam - tam_r, wall_tam , depth- wall_tam));


	if (i.top) createWall(_pos + Vector3(0, height, depth), Vector3(width + wall_tam - tam_r, wall_tam , wall_tam - tam_r));

	if (i.down) createWall(_pos + Vector3(0, height, -depth), Vector3(width + wall_tam - tam_r, wall_tam, wall_tam - tam_r));


}

Hole::~Hole()
{
	
	for (auto obj : walls) {
		delete obj;
	}
	for (auto obj : floors) {
		delete obj;
	}
}

void Hole::createWall(Vector3 pos, Vector3 tam)
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
