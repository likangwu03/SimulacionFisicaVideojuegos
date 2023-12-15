#pragma once
#include "SolidGenerator.h"
class AreaSRGenerator :public SolidGenerator
{
public:
	// model seria un DynamicObject que no se crear su existencia en la escena
	AreaSRGenerator(SolidSystem* system, Vector3 pos, int n, double f,Vector3 area,  DynamicObject* model);

	virtual void generateSolids();
	virtual void update(double t);

protected:
	Vector3 _area;
};

