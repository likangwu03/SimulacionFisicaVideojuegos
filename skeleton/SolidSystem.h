#pragma once
#include "System.h"
#include "SolidGenerator.h"
#include "AreaSRGenerator.h"
#include "SolidForceRegistry.h"
class SolidSystem:public System
{
protected:
	std::vector <SolidGenerator*> _generators;
	std::list <DynamicObject*> _objs;

	std::list <SolidForceGenerator*> _forceGenerators;
	SolidForceRegistry objForceRegistry;

public:
	SolidSystem(Scene* scene);

	virtual ~SolidSystem();

	// Integrates the particles and checks for its lifetime, setc!
	void update(double t) override;

	void addGenerator(SolidGenerator* g) {
		_generators.push_back(g);
	}

	
	void addForce(SolidForceGenerator* g);

	void removeForce(SolidForceGenerator* g);
	
	void refresh();

	//template <typename Valor>
	void addObj(DynamicObject* o);
};

