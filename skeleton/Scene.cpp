#include "Scene.h"
#include "checkML.h"

Scene::Scene(PxData data) : hdlrs_(), objsByGroup_(),_data(data) {
	cam = GetCamera();
	for (auto& groupEntities : objsByGroup_) {
		groupEntities.reserve(100);
	}
}
Scene::~Scene() {
	for (auto& ents : objsByGroup_) {
		for (auto e : ents)
			delete e;
	}
	
	for (auto& ents : objsAux_) {
		for (auto e : ents)
			delete e;
	}


	for (auto s : systems) {
		delete s;
	}
	
}

void Scene::addObject(Object* obj, SFV::grpId_type gId) {
	obj->setAlive(true);
	obj->setContext(this);
	objsByGroup_[gId].push_back(obj);
}

void Scene::addObject2(Object* obj, SFV::grpId_type gId) {
	obj->setAlive(true);
	obj->setContext(this);
	objsAux_[gId].push_back(obj);
}



const auto& Scene::getObjects(SFV::grpId_type gId) {
	return objsByGroup_[gId];
}

void Scene::refresh() {
	for (SFV::grpId_type gId = 0; gId < SFV::maxGroupId; gId++) {
		auto& grpEnts = objsByGroup_[gId];
		grpEnts.erase(
			std::remove_if(grpEnts.begin(), grpEnts.end(),
				[](Object* e) {
					if (e->isAlive()) {
						return false;
					}
					else {
						delete e;
						return true;
					}
				}),
			grpEnts.end());
	}
}


void Scene::update(double t) {
	for (System* sys : systems) {
		if(sys->isActive())sys->update(t);
	}

	for (auto& ents : objsByGroup_) {
		for (auto& ent : ents) {
			ent->integrate(t);
		}
	}

	addAux();
}

void Scene::addAux()
{
	int cont = 0;
	for (auto& ents : objsAux_) {
		for (auto& ent : ents) {
			objsByGroup_[cont].push_back(ent);
		}
		ents.clear();
		cont++;
	}
}

void Scene::keyPress(unsigned char key) {

	for (System* sys : systems) {
		sys->keyPress(key);
	}

	for (auto& ents : objsByGroup_) {
		for (auto& ent : ents) {
			ent->keyPress(key);
		}
	}
}

void Scene::handleMouse(int button, int state, int x, int y)
{
	for (System* sys : systems) {
		sys->handleMouse(button, state, x, y);
	}
}

void Scene::handleMotion(int x, int y)
{
	for (System* sys : systems) {
		sys->handleMotion(x, y);
	}
}


void Scene::addSystem(System* s) {
	systems.push_back(s);
}

System* Scene::getSystem(string id) {
	if (systemsHdlrs.count(id))return systemsHdlrs[id];
	else return nullptr;
}