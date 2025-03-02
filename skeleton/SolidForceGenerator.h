#pragma once

#include "DynamicObject.h"

class SolidForceGenerator
{
protected:
	SolidForceGenerator(double duration = -1) :_duration(duration) {}

	bool _active = true;
	std::string _name;
	double _t = 0.0; // If starting negative --> eternal
	double _duration = -1e10;
	bool _alive = true;
	bool _add = true;
public:
	virtual ~SolidForceGenerator() {}

	virtual void updateForce(DynamicObject* obj, double t) = 0;

	inline bool updateTime(double t) {
		_t += t;
		return _t < _duration || _duration < 0.0; // Devuelve true si ya era cero o si es positivo
	}

	void setActive(bool a) { _active = a; };
	bool getActive() { return _active; };

	void setAlive(bool a) { _alive = a; }
	bool isAlive() { return _alive; }

	void setAdd(bool a) { _add = a; }
	bool needAdd() { return _add; }
};

