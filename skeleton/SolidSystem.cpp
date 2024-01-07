#include "SolidSystem.h"
#include "Scene.h"
SolidSystem::SolidSystem(Scene* scene):System(scene, SFV::SystemId::_sys_SOLID)
{
	for (auto obj : *scene->getGroup(SFV::_grp_SOLID)) {
		_objs.push_back((DynamicObject*)obj);
	}
}

SolidSystem::~SolidSystem()
{
	_objs.clear();
	
	for (auto g : _generators) {
		delete g;
	}

}

void SolidSystem::update(double t)
{
	for (auto g : _generators) {
		g->update(t);
	}

	for (auto fg : _forceGenerators) {
		if (!fg->updateTime(t)) {
			fg->setActive(false);
		}
	}

	objForceRegistry.updateForces(t);

	refresh();
}

void SolidSystem::refresh()
{
	auto it = _objs.begin();
	while (it != _objs.end()) {
		if ((*it)->getTime() > (*it)->getDuration() && (*it)->getDuration() > 0) {
			(*it)->setAlive(false);
			objForceRegistry.deleteObjRegistry(*it);
			it = _objs.erase(it);

		}
		else {
			++it;
		}
	}

	auto it2 = _forceGenerators.begin();
	while (it2 != _forceGenerators.end()) {
		if (!(*it2)->isAlive()) {

			objForceRegistry.deleteForcesRegistry(*it2);

			it2 = _forceGenerators.erase(it2);
		}
		else {
			++it2;
		}
	}
}

void SolidSystem::addObj(DynamicObject* o)
{
	_objs.push_back(o);
	_scene->addObject(o);
	for (auto f : _forceGenerators) {
		if(f->needAdd())objForceRegistry.addRegistry(f, o);
	}
	
}



void SolidSystem::addForce(SolidForceGenerator* g)
{
	_forceGenerators.push_back(g);
	if (!g->needAdd()) return;
	for (auto p : _objs) {
		objForceRegistry.addRegistry(g, p);
	}
}

void SolidSystem::removeForce(SolidForceGenerator* g)
{
	objForceRegistry.deleteForcesRegistry(g);
	_forceGenerators.remove(g);
	delete g;
}
