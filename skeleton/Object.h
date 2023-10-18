#pragma once
class Scene;
class Object
{
protected:
	bool alive_;
	Scene* scene_;

public:
	Object() :scene_(nullptr), alive_() {};
	virtual ~Object() {};
	inline void setContext(Scene* scene) { scene_ = scene; };
	inline bool isAlive() { return alive_; }
	inline void setAlive(bool alive) { alive_ = alive; }

	virtual void integrate(double t) {};
	virtual void keyPress(unsigned char key) {};

};

