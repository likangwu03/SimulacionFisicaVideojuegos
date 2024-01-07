#pragma once
#include "Particle.h"
#include <iostream>
class ForceGenerator {
protected:
	ForceGenerator(double duration = -1) :_duration(duration) {}

	bool _active = true;
	std::string _name;
	double _t = 0.0; // If starting negative --> eternal
	double _duration = -1e10;
	bool _alive = true;
	bool _add = true;
public:
	virtual ~ForceGenerator(){}

	virtual void updateForce(Particle* particle, double t) = 0;

	inline bool updateTime(double t) {
		_t += t;
		return _t < _duration || _duration < 0.0; // Devuelve true si ya era cero o si es positivo
	}
	//virtual ~ForceGenerator() {}

	void setActive(bool a) { _active = a; };
	bool getActive() { return _active; };

	void setAlive(bool a) { _alive = a; }
	bool isAlive() { return _alive; }

	void setAdd(bool a) { _add = a; }
	bool needAdd() { return _add; }
};
