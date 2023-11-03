#pragma once
#include "def.h"
class Scene;
class System {
public:
	System(Scene* scene, SFV::system_type type= SFV::_sys_DEFAULT) {
		_type = type;
		_scene = scene;
	}
protected:
	Scene* _scene;
	SFV::system_type _type;
public:
	virtual void update(double t)=0;

	SFV::system_type getType() {
		return _type;
	}

	Scene* getScene() { return _scene; }
};