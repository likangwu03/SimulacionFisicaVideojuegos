#include "AreaSRGenerator.h"
#include "SolidSystem.h"

AreaSRGenerator::AreaSRGenerator(SolidSystem* system, Vector3 pos, int n, double f, Vector3 area,DynamicObject* model) :
	SolidGenerator(system, pos, n, f), _area(area)
{
	_model = model;
	addUniformDistribution(pos.x - _area.x/2, pos.x + _area.x/2);
	addUniformDistribution(pos.y , pos.y + _area.y);
	addUniformDistribution(pos.z - _area.z/2, pos.z + _area.z/2);
}

void AreaSRGenerator::generateSolids()
{
	DynamicObject::ObjectInfor infor = _model->getInfor();
	infor.model = false;
	for (int i = 0; i < _nObject; ++i) {
		infor.pos = Vector3(uniform_distributions[0](gen), uniform_distributions[1](gen), uniform_distributions[2](gen));
		DynamicObject* obj = _model->createOther(infor);
		_system->addObj(obj);
	}
}

void AreaSRGenerator::update(double t)
{
	_cont += t;
	if (_cont > _frequency ) {
		_cont = 0;
		generateSolids();
	}
}
