#pragma once

class Scene;
class System {
public:
	System(Scene* scene) {
		_scene = scene;
	}
protected:
	Scene* _scene;
public:
	virtual void update(double t)=0;
};