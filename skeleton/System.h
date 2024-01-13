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
	bool active = true;
public:

	bool isActive() { return active; }

	void setActive(bool a) {  active=a; }

	virtual void update(double t)=0;

	SFV::system_type getType() {
		return _type;
	}

	Scene* getScene() { return _scene; }

	virtual void keyPress(unsigned char key) {};

	virtual void handleMouse(int button, int state, int x, int y) {};
	virtual void handleMotion(int x, int y) {};

};